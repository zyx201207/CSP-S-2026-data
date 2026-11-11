#include<bits/stdc++.h>
using namespace std;
long long n,ans,m;
string a;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		int t;
		char l;
		cin>>t>>l;
		m+=t;
		for(long long j=1;j<=t;j++){
			a+=l;
		}
	}
	for(long long i=0,j=m-1;i<=m/2;i++,j--){
		if(a[i]!=a[j]){
			a[i]=a[j];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
