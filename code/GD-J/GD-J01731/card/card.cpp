#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],la[500010],fr[500010],c[500010],t[500010],tmp,ans[500010],fl[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fl[i]=1;
		cin>>a[i];
		fr[i]=la[a[i]];
		if(la[a[i]]==0)c[a[i]]=i;
		la[a[i]]=i;
		t[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		tmp=i;
		while(tmp<=n){
			ans[a[tmp]]++;
			tmp=la[a[tmp]];
			tmp++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
