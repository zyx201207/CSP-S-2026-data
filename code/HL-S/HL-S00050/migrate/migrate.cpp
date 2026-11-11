#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+10;
int c,T,n;
LL d,a[N];
int nxt[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=l+r+1>>1;
			if(a[mid]<=a[i]+d)l=mid;
			else r=mid-1;
		}
		nxt[i]=l;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		int j=nxt[i],cnt=0,last=i;
		while(j^nxt[j]){
			int lstcnt=cnt;
			if(!cnt){
				if(j-last<2)ans+=nxt[j-1]-j;
				else ans+=nxt[j-1]-nxt[j-2];
			}
			if(nxt[j-1]==nxt[j])cnt++;
			if(nxt[j-2]==nxt[j])cnt++;
			if(cnt>1)break;
			if(lstcnt)ans++;
			last=j,j=nxt[j];
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	return 0;
} 
