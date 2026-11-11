#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
int a[maxn];
bool vis[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int lg=31;lg>=0;lg--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((a[i]>>lg&1)&&vis[i]==false) cnt++;
		}	
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(!(a[i]>>lg&1)) vis[i]=true;
			}
		}
	}
	int l=1;
	while(vis[l]==true) l++;
	int ans=a[l];
	l++;
	m--;
	while(m--){
		if(vis[l]==false){
			ans&=a[l];
		}
		l++;
	}
	cout<<ans;
	return 0;
}
