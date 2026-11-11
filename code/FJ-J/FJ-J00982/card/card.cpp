#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

int n,m;
int a[N];
ll s[N];
ll dp[N];
int lst[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	dp[1]=1;
	s[a[1]]++;
	for(int i=2;i<=n;i++){
		dp[i]=1;
		if(i==lst[a[i]]) dp[i]+=s[a[i]];
		if(lst[a[i-1]]==i-1) dp[i]+=dp[i-1];
		s[a[i]]+=dp[i];
	}
	for(int i=1;i<=m;i++){
		cout<<dp[lst[i]]<<' '; 
	}
	return 0;
}
