#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a,cnt,f[N],maxx=-2e9;
string t,s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>t;
		maxx=max(maxx,a);
		s+=t,f[i]=a;
	}
	if(maxx<=500){
		string k;
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<f[i];j++){
				k+=s[i];
			}
		for(int i=0;i<k.size()/2;i++)
			if(k[i]!=k[k.size()-1-i])ans++;
		cout<<ans;
		return 0;
	}
	int l=0,r=n-1;
	if(l>r)swap(l,r);
	while(l<r){
		if(s[l]==s[r]){
			int m=min(f[l],f[r]);
			f[l]-=m,f[r]-=m;
			if(f[l]==0)l++;
			if(f[r]==0)r--;
		}
		else if(s[l]!=s[r]){
			int mi=min(f[l],f[r]);
			f[l]-=mi,f[r]-=mi;
			if(f[l]==f[r])f[l]+=mi;
			cnt+=abs(f[l]-f[r]);
			if(f[l]==0)l++;
			if(f[r]==0)r--;
		}
	}
	cout<<cnt;
	return 0;
}
