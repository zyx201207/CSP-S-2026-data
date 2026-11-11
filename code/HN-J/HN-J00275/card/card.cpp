#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[500005],go[500005],l[500005];
bool fx[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])f=1; 
	}
	if(!f){
		for(int i=1;i<=n;i++)ans[a[i]]=i;
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	for(int bg=1;bg<=n;bg++){
		for(int i=bg;i<=n;i++){
			if(l[a[i]])go[l[a[i]]]=i-1;
			l[a[i]]=i;
		}
		for(int i=bg;i<=n;i++){
			if(go[i]){
				i=go[i];
				go[i]=0;
				continue;
			}
			if(fx[a[i]])continue;
			ans[a[i]]++;
			fx[a[i]]=1;
		}
		for(int i=1;i<=m;i++)fx[i]=l[i]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
