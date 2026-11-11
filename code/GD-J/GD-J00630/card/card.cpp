#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
ll n,m,s[500050],fro[300050],a[500050],tom,cnt[300050],ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		if(i!=1&&s[i]>=s[i-1])
			ans++;
	}
	if(ans==n-1){
		for(ll i=n;i>=1;i--){
			if(i<n&&s[i]==s[i+1])
				continue;
			cnt[s[i]]+=i;
		}
		for(ll i=1;i<=m;i++)
			cout<<cnt[i]<<" ";
		return 0;
	}
	for(ll i=1;i<=n;i++){
		tom=0;
		for(ll j=i;j<=n;j++){
			if(fro[s[j]]!=0&&fro[s[j]]<=tom)
				tom=fro[s[j]];
			else
				a[++tom]=s[j],fro[s[j]]=tom;
		}
		for(ll j=1;j<=tom;j++)
			cnt[a[j]]++;
		for(ll j=1;j<=m;j++)
			fro[j]=0;
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

