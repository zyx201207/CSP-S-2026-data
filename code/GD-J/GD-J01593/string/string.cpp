#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
	long long nu;
	long long ki;
};
node vis[200100];
int dis[36];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int vtt=0;
	int kind=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		char b;
		cin>>b;
		vis[vtt].nu=a;
		vis[vtt].ki=b-'a';
		if(dis[b-'a']==0){
			kind++;
		}
		dis[b-'a']=1;
		vtt++;
	}
	if(kind==1){
		cout<<0;
		return 0;
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<=r){
		if(vis[l].ki==vis[r].ki){
			if(vis[l].nu==vis[r].nu){
				l++;
				r--;
				continue;
			}else {
				if(vis[l].nu>vis[r].nu){
					vis[l].nu-=vis[r].nu;
					r--;
				}else if(vis[l].nu<vis[r].nu){
					vis[r].nu-=vis[l].nu;
					l++;
				}
			}
		}else {
			if(vis[l].nu==vis[r].nu){
				ans+=vis[l].nu;
				l++;
				r--;
				continue;
			}else {
				ans+=min(vis[l].nu,vis[r].nu);
				if(vis[l].nu>vis[r].nu){
					vis[l].nu-=vis[r].nu;
					r--;
				}else if(vis[l].nu<vis[r].nu){
					vis[r].nu-=vis[l].nu;
					l++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
