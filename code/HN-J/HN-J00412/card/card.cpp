#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,cnt;
int a[N],d[N];
unordered_map<int,int>mp,mp2,mp3;
queue<int>s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]++;
		mp2[a[i]]++;
		mp[a[i]]=i;
		if(mp2[a[i]]>=2){
			mp2[a[i]]--;
			d[mp[a[i]]-1]--;
			d[mp[a[i]]]++;
		}
	}
	for(int i=1;i<=n;i++){
		d[i]+=d[i-1];
		mp3[a[i]]=d[i];
	}
	for(int i=1;i<=m;i++) cout<<mp3[i]<<" ";
	return 0;
}
