#include <bits/stdc++.h>
using namespace std;
int n,m;
int zin,zout;
int a[200005],b[100005],c[100005],d[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		zout ++;
	}
	while(zout){
		if(b[a[zout]] == 0){
		b[a[zout]] ++;
			c[zin] = a[zout];
			zin ++;
			a[zout] = 0;
			zout --;
		}else{
			while(zin){
				if(c[zin] == a[zout]) break;
				a[zout] = c[zin];
				b[c[zin]] --;
				c[zin] = 0;
				zin --;
				zout ++;
			}
		}
		for(int i = 1;i <= m;i ++) if(b[i] >= 0) d[i] ++;
	}
	for(int i = 1;i <= m;i ++) cout << d[i] << " ";
	return 0;
}
