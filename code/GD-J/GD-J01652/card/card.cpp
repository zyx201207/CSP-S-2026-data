#include <bits/stdc++.h>
#define MAXN 2000005
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	stack a[MAXN];
	int cnt[MAXN]=0;
	int ans[MAXN]=0;
	int f[MAXN]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		if(cnt[a[i]]>1){
			while(a.top!=a[i]) a.pop
			a.pop;
			a.push_back(a[i]);
			cnt[a[i]]=0;
			f[a[i]]=i;
		}
	}
	for(int i=0;i<n;i++){
		cout<<f[a[i]]=i;
	}
 
