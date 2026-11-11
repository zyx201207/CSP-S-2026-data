#include<bits/stdc++.h>
using namespace std;
const int N=500010,M=300010;
int n,m;
int a[N],b[N];
bool v[M];
int cnt[M];
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int pos=n;
	for(int i=n;i>=1;i--){
		memset(v,0,sizeof(v));
		b[pos]=a[i];
		if(mp[a[i]]!=0){
			for(int j=pos+1;j<mp[a[i]];j++)mp[b[j]]=0;
			pos=mp[a[i]];
		}else{
			mp[a[i]]=pos;
		}
		for(int j=pos;j<=n;j++){
			if(!v[b[j]])cnt[b[j]]++;
			v[b[j]]=1;
		}
		pos--;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
}
