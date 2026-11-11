#include<bits/stdc++.h>
using namespace std;
char c[100000009],b;
long long K,k=1,a,ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>b;
		K=k;
		for(int j=K;j<K+a;j++){
			c[k]=b;
			k++;
		}
	}
	for(int i=1;i<=((k-1)/2);i++){
		if(c[i]!=c[k-i])ans++;
	} 
	cout<<ans; 
	return 0;
}
