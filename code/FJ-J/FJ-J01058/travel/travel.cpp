#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2,n=1;
	cin>>c1>>s1>>c2>>s2;
	for(int i=2;i<=c1;i++){
		i=c1;
	}
	for(int i1=2;i1<=c2;i1++){
		i1=c2;
	}
	for(int j=0;j<=s1;j++){
		j=s1;
	}
	for(int j1=0;j1<=s2;j1++){
		j1=s2;
	}
	
	if(s1+=s2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s2+=s1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1=s2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1=c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
