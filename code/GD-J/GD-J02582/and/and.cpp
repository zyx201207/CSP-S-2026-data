#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
using namespace std;
const int mo1=1e9+7,mo2=1e9+9;
int n,m,a[200010],b[78],c[78],ma,f[200010];
void cpu(int x,int s){
	for(int i=s;i<=n-(m-x);i++){
		b[x]=i;
		if(x==m){
			int z=a[b[1]];
			for(int i=2;i<=m;i++) z&=a[b[i]];
			ma=max(ma,z);
		}
		else cpu(x+1,i+1);
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1,x;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int po=1,z=0;
	b[z]=0;
	for(int i=1;i<=n;i++)
		if(a[i]>po){
			c[z]=i-1;
			while(a[i]<=po) po*=2,z++;
			b[z]=i;
		}
	c[z]=n;
	for(int t=z;t>=0;t--)
		if(c[t]-b[t]+1>=m){
			int k=a[c[t]],p=0,pp=0,zxx=a[c[t]],q=0;
			while(k>0) pp++,p=(k%2==1? pp : p ),k/=2;
			for(int i=c[t]-1;i>=b[t]&&q<m;i++){
				int kk=a[i];
				for(int j=1;j<=pp;j++) kk/=2;
				if(kk%2==1) f[i]=1,q++,zxx&=a[i];
			}
			if(q<m) zxx=a[c[t]];
			for(int i=c[t]-1,j=1;j<=m;i--,j++) zxx&=a[i];
			cout<<zxx;
			return ;
		}
	cpu(1 , 1),cout<<ma;
}
signed main(){
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	freopen("iii.txt" , "r" , stdin);
	freopen("and.txt" , "w" , stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
