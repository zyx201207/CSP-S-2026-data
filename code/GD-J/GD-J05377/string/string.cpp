#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
string s;
long long n,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
		if(a[i]<1000000) for(int j=0;j<a[i];j++) s+=c[i];
	}
	long long ans=0;
	if(k>100000000){
		cout<<k/2;
		return 0;
	}
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[k-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
