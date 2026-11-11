#include <bits/stdc++.h>
using namespace std;
int p[200010][35],cnt[200010],s=1;
void r(int l){
	int k=l;
	while(k){
		cnt[s]++;
		k/=2;
	}
	for(int i=cnt[s];i>=1;i--){
		p[s][i]=l%2;
		l/=2;
	}
	s++;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010],b[200010],c=0,maxn=-1,f=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		r(a[i]);
	}
	int e=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) e=0;
	}
	if(e){
		int cnt=0,ans=1;
		while(n!=1){
			cnt++;
			n/=2;
		}
		if(cnt>=m){
			for(int i=1;i<cnt-m+1;i++){
				ans=ans+i*2;
			}
			cout << ans;
			return 0;
		}
		cout << 0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c=0;
			if(cnt[i]>cnt[j]) continue;
			int g=cnt[i],u=cnt[i],w=cnt[j];
			for(int z=1;z<=g;z++){
				if(p[i][u]!=p[j][w]) c=1;
				u--;w--;
			}
			if(!c) b[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]<m) b[i]=-1;
	}
	for(int i=1;i<=n;i++){
		if(maxn<a[i]&&b[i]!=-1) maxn=a[i],f=0;
	}
	if(f) cout << 0;
	else cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
