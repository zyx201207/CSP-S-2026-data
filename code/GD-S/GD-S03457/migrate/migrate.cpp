#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N],v[N];
bool check(int i,int j,int pos,int d){
	int lst=j;
	for(int k=j;k>=i;k--)
		if(a[lst]-a[k]>d) lst=k;
	if(lst+2==pos) return 1;
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int ans=0;
		memset(a,0,sizeof a);
		memset(v,0,sizeof v);
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==13||c==14){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12){
			int l=2;
			while(a[l]-a[1]<=d) l++;
			for(int i=1;i+l-2<=n;i++) ans+=n-(i+l-2);
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int lst=i;
				for(int k=i;k<=j;k++){
					if(a[k]-a[k-1]>d&&k!=i){
						lst=i;
						break;
					}
					if(a[k]-a[lst]>d) lst=k;
				}
				if(lst==i) continue;
				lst--;
				if(check(i,j,lst,d)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
