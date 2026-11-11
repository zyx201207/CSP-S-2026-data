#include <bits/stdc++.h>
using namespace std;
const int N=105;
struct stu{
	int a,c,b,d;
}t[N];
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
		cin>>t[i].a>>t[i].b>>t[i].c>>t[i].d;
	}
	for(int i=1;i<=1;i++){
		if(t[i].a==t[i].c){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	for(int i=1;i<=1;i++){
		if(t[i].b==t[i].d){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	for(int i=1;i<=1;i++){
		if(t[i].b==t[i+1].d){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	for(int i=1;i<=1;i++){
		if(t[i+1].b==t[i-1].d or t[i-1].b==t[i+1].d){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	return 0;
}