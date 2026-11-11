#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
//O(n log n)

ll a[maxn],f[maxn];
ll ans;
unsigned ll n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	//m==0
	if(!m){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]) f[i]=f[i-1]+1;
			else f[i]=1;
			ans=max(f[i],ans);
		}
		cout<<ans; return 0;
	}

	//shuangzhizhenfa
	sort(a+1,a+n+1);
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			unsigned ll maxx=a[j],need=0;

			for(int k=i;k<j;k++){
				need+=maxx-a[k];
				//cout<<need<<"\n";
				}

				//cout<<"\n";
			if(need<=m){
				if(ans<j-i+1) {
					ans=j-i+1;
					if(j==n){cout<<ans; exit(0);}

				}
			}
			else{
				break;
			}
		}
	}

	cout<<ans;
	return 0;
}
