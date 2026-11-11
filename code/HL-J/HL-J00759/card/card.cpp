#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],cnt[200005];
int main(){
freopen("card.in","r",stdin);freopen("card.out","w",stdout);
ll n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int i=1;i<=n;i++){
	bool vis[20005]={0};
	bool s[20005]={0};
	int last[20005]={0};
	for(int j=i;j<=n;j++){
		s[j]=true;
		
	if(vis[a[j]]==true){
		for(int k=last[a[j]];k<j;k++){
			vis[a[k]]=false;
			last[a[k]]=0;
			s[k]=false;
		}
	}else{last[a[j]]=j;
	vis[a[j]]=true;}
	}
	for(int l=1;l<=n;l++){
		if(s[l])cnt[a[l]]++;
	}
}
for(int i=1;i<=m;i++){
	cout<<cnt[i]<<' ';
}
return 0;
}
