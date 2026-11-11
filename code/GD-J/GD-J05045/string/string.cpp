#include<bits/stdc++.h>
using namespace std;
string zf;
long long sum=0,n,t=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a;
		cin>>b;
		for(int j=t;j<(t+a);j++){
			zf[j]=b;
		}
		t+=a;
	}
	for(int i=1;i<=zf.size()/2;i++){
		for(int j=zf.size();j>=zf.size()/2;j--){
			if(zf[i]!=zf[j]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
