#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1;
	cin>>b>>b1;
	if(a==b){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int sum=0;
	for(int i=0;i<3;i++){
		if('0'<a1[i]&&a1[i]<'9'){
			if(a1[i]==b1[i]){
				sum++;
			}
		}
	}
	if(sum>=2){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<3;i++){
		if('A'<=a1[i]&&a1[i]<='C'){
			if('A'<=b1[i]&&b1[i]<='C'){
				cout<<1;
			}else{
				cout<<0<<0;
				return 0;
			}
		}else if(a1[i]=='D'||a1[i]=='F'){
			if('D'==b1[i]||b1[i]<='F'){
				cout<<1;
			}else{
				cout<<0<<0;
				return 0;
			}
		}
	}
	if(a1[a1.size()-1]+1==b1[b1.size()-1]||a1[a1.size()-1]==b1[b1.size()-1]+1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
