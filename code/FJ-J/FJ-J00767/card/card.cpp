#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],c[N],cnt[M];
bool b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool flag=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i-1]>a[i]) flag = 0;
	}
	if(flag){
		for(int i=n;i>=1;i--){
			if(!cnt[a[i]]) cnt[a[i]] = i;
		}
	}else{
		for(int i=1;i<=n;i++){
			int p=1;
			for(int j=i;j<=n;j++){
				if(b[a[j]]){
					for(int k=p-1;;k--){
						if(c[k]==a[j]){
							p = k;
							break;
						}
						b[c[k]] = 0;
						c[k] = 0;
					}
				}else{
					b[a[j]] = 1;
					c[p] = a[j];
				}
				p++;
			}
			for(int i=1;i<=m;i++) cnt[i] += b[i];
			memset(b,0,sizeof(b));
			memset(c,0,sizeof(c));
		}
	}
	for(int i=1;i<=m;i++) cout << cnt[i] << ' ';
	cout << '\n';
	return 0;
}
//40tps
