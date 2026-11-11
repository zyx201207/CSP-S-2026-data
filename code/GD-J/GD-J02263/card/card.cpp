#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m,a[N],f[N],s[N],c[N],ans[N],t[N];
//s[i] 下一个c[i]的位置索引 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
		f[i] = i;
	}
	for(int i = n;i>=1;i--){
		s[i] = t[c[i]];
		t[c[i]] = i;
	}
	for(int i = 1;i<=n;i++){
		a[i]+=a[i-1];
		f[i]+=a[i];
		ans[c[i]] = max(f[i],ans[c[i]]);
		if(s[i]!=0){
			a[i+1]-=f[i];
			a[s[i]]+=f[i];
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

