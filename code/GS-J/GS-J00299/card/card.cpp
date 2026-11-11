#include<bits/stdc++.h>
using namespace std;
long long a,c,d,b,e;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	long long n[a+5]={},m[b+5]={};
	for(long long j=0;j<a;j++){
		cin>>n[j];
	}if(b==1){
		cout<<a;
		return 0;
	}
	for(long long i=1;i<=b;i++){
		for(long long k=0;k<a;k++){
			for(long long j=k;j<a;j++){
				if(n[j]==i){
					if(m[i]==k){
						m[i]++;
					}
				}
			}
		}
	}for(long long j=1;j<=b;j++){
		if(j==2){
			cout<<(m[j]-1)<<" ";
		}else cout<<m[j]<<" ";
	}
	return 0;
	}
