#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,k;
string s,b[200005];
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","s",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i]>>b[i];
	
	for(int j=0;j<n;j++){
		long long mi=min(mi,ans);
		ans=mi+a[0];
		for(int i=1;i<n;i++)
		{
		if(b[i]==b[i-1]) ans+=a[i];
		else {k=1;break;}
		}
	}
	
	if(k==0) cout<<0;
	else cout<<ans;
	return 0;
} 
