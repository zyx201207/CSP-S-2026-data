#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],ji[N];
map<int,int> mp;
map<int,int> last,f;
void solve(int k){
	if(k>n) return;
	int l=0;
	for(int i=k;i<=n;i++){
		if(mp[a[i]]!=0){
			l=i;
			for(int j=last[a[i]];j<l;j++){
				if(f[j]==0) mp[a[j]]--;
				f[j]=1;
			} 
		} 
		mp[a[i]]++;
		last[a[i]]=i;
	}
	if(l==0){
		for(int i=1;i<=m;i++){
			if(mp[i]>0) ji[i]+=last[i]-k+1;
		}
		return;
	}
	for(int j=1;j<=m;j++){
		if(mp[j]>0) ji[j]++; 
	}
	mp.clear();
	last.clear();
	f.clear();
	solve(k+1);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	solve(1);
	for(int i=1;i<=m;i++) cout<<ji[i]<<' ';
	return 0;
}