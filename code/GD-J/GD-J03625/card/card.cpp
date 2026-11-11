#include <bits/stdc++.h>
using namespace std;
struct X{
	int v,id;
};
int n,m,a[514514];
X w[314514];
int sum[314514];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			w[j].v=0;
			w[j].id=0;
		}
		for(int j=i;j<=n;j++){
			if(w[a[j]].v){
				for(int k=w[a[j]].id;k<j;k++){
					w[a[k]].v=0;
					w[a[k]].id=0;
				}
				w[a[j]].v=1;
				w[a[j]].id=j;
			}else{
				w[a[j]].v=1;
				w[a[j]].id=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(w[j].v)sum[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << sum[i] << " ";
	}
	return 0;
}
