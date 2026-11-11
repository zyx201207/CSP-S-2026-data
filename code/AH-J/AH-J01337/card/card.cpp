#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int s[300005],tp;
int cnt[300005],last[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=0;
		last[i]=cnt[a[i]];
		cnt[a[i]]=i;
		if(last[i]!=0)s[last[i]]++,s[i]--;
	}
	if(n<=500){
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++){
		tp=1;
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==0){
				s[tp++]=a[j];
				cnt[a[j]]=1;
			}
			else{
				while(s[tp-1]!=a[j]){
					tp--;
					cnt[s[tp]]=0;
				}
			}
		}
		while(tp>1){
			ans[s[tp-1]]++;
			tp--;
		}
		s[1]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	else{
		memset(ans,0,sizeof(ans));
		if(f){
			for(int i=1;i<=n;i++){
				if(a[i+1]!=a[i])ans[a[i]]=i;
			}
			for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
			return 0;
		}
		else{
			memset(ans,128,sizeof(ans));
			s[0]=0;
			for(int i=1;i<=n;i++){
				s[i]+=s[i-1];
				if(s[i]==0&&cnt[a[i]]==i){
					ans[a[i]]=i;
				}
			}
			ans[a[n]]=n;
			for(int i=n-1;i>=1;i--){
				if(cnt[a[i]]!=i)continue;
				for(int j=i-1;j>=last[i]+1;j--){
					if(cnt[a[j]]==j)ans[a[j]]=max(ans[a[j]],(j-last[i]));
				}
				//ans[a[i]]=max(ans[a[i]],(i-last[i]+1));
			}
			for(int i=1;i<=m;i++){
				cout<<ans[i]<<" ";
			}
		}
	}
	return 0;
}
