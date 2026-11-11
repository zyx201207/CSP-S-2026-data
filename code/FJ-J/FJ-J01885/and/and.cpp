#include <bits/stdc++.h>
using namespace std;
long long n,s,num[1000005],sum=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(num[i]<num[i+1]){
				int t=num[i];
				num[i]=num[i+1];
				num[i+1]=t;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==s){
			cout<<num[i];
		} 
	}
	return 0;
} 
