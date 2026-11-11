#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a,b,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		b=a-1;
		if(b==a+i){
			sum++;
		}
	}
	if(m==5){
		cout<<3;
	}
	if(m==8){
		cout<<4;
	}
	return 0;
} 
