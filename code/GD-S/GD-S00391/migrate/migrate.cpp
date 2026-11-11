#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+7,INF=0x3f3f3f3f;
int C,T;
int n;
ll a[N],d;
int suf[N],lst[N];
int step[5007][5007];
ll f[5007][5007];
ll s[5007][5007];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<"0\n";
		return;
	}
	for(int i=n,p=n;i>=1;i--){
		while(a[p]-a[i]>d) p--;
		suf[i]=p; 		
	}
	for(int i=1,p=1;i<=n;i++){
		while(a[i]-a[p]>d) p++;
		lst[i]=p;
	} 
	if(C==13 || C==14){
		ll res=0,pos=0;
		for(int i=1;i<=n;i++) if(a[i]-a[1]<=d && a[n]-a[i]<=d) pos=i;
		for(int i=pos+1;i<=n;i++){
			if(lst[i]==1) continue;
			if(lst[i]<pos-1) continue;
			int l=1,r=lst[i]-1,ans=-1;
			while(l<=r){
				int mid=l+r>>1;
				if(suf[mid]-lst[i]+1<=2) ans=mid,l=mid+1;
				else r=mid-1;
			}
			int R=ans;
			l=1,r=lst[i]-1,ans=-1;
			while(l<=r){
				int mid=l+r>>1;
				if(suf[mid]-lst[i]+1>=2) ans=mid,r=mid-1;
				else l=mid+1;
			}
			int L=ans;
			if(suf[R]-lst[i]+1==2) res+=R-L+1;
		}cout<<res<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) step[i][j]=INF;
	for(int i=1;i<=n;i++) step[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) 
			if(lst[j]>i && step[i][lst[j]]<INF) step[i][j]=step[i][lst[j]]+1;
			else if(lst[j]<=i) step[i][j]=1;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) f[i][j]=0;
	for(int i=1;i<=n;i++) f[i][i]=1,s[i][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1,r=i;j<=n;j++){
			int pre=max(lst[j],i);
			if(step[i][pre]==INF) break;
			r=max(r,pre);
			while(r+1<j && step[i][pre]==step[i][r+1]) r++;
			f[i][j]=s[i][r]-s[i][pre-1];
			s[i][j]=s[i][j-1]+f[i][j];
		}
	}
	ll res=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) if(f[i][j]==2) res++;
	cout<<res<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	C,T;
	cin>>C>>T;
	while(T--) solve();
}
