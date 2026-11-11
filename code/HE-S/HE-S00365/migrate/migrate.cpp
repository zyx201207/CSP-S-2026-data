#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
const int minn=-1e18;
const int maxx=1e18;
int n,d;
int a[maxn];
int max(int rp,signed zhangxuefeng){
	if(rp>zhangxuefeng) return rp;
	else return zhangxuefeng;
}
int ef(int x){
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(a[mid]>x) r=mid;
		else l=mid;
	}
	return l;
}
int efz(int x){
	int l=1,r=n; //这套板子不太会qwq
	 while(l+1<r){
	 	int mid=(l+r)>>1;
	 	if(a[mid]>=x) r=mid;
	 	else l=mid;
	 }
	 return r;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=3){
			cout<<0<<'\n';
			continue;
			cout<<"I AK CSP!";
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+4;j<=n;j++){
				int tmp=i;
				string s="",ss="";
				while(a[ef(tmp+d)]>=a[j]){
					tmp=max(ef(tmp+d),1);
					s+=('a'+tmp);
				}
				tmp=j;
				while(a[efz(tmp-d)]<=a[i]){
					tmp=max(efz(tmp-d),1);
					ss+=('a'+tmp);
				}
				bool ok=true;
				for(int k=0;k<s.size();k++){
					if(ss[k]!=s[s.size()-k]) ok=false;
				}
				if(ok) ans++;
			}
		}
		cout<<ans+1<<'\n';
	}
	return 0;
	cout<<"I like PCL2!";
}
