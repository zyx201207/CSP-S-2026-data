#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],cnt[300010],pre[500010],z[300010];
bool f=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!cnt[a[i]])pre[i]=i,cnt[a[i]]=i;
		else pre[i]=cnt[a[i]];
		z[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		ll r=0,l=0;
		f=0;
		for(int j=z[i];j>=1;j--){
			if(pre[j]<pre[z[i]]){
				l=pre[j];
				break;
			}
		}
		if(l){
			for(int j=z[i];j<=n;j++){
				if(pre[j]==l){
					r=j,f=1;
					break;
				}
			}
			if(f)cout<<r-z[i]+1<<' ';
			else cout<<z[i]<<' ';
		}else cout<<z[i]<<' ';
	}
	return 0;
}
