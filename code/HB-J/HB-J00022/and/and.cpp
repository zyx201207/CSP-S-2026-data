#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
struct note{
	long long c;
	long long e;
	long long d;
}y[200005];
bool cmp(note x,note b){
	if(x.d != b.d){
		return x.d > b.d;
	}
	return x.e > b.e; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		long long o=a[i];
		y[i].c=o;
		long long u=0,w=0;
		while(o != 0){
			if(o % 2 == 1){
				u++;
			}else{
				w++;
			}
			o/=2;
		}
		y[i].d=u+1;
		y[i].e=w;
	}
	sort(y+1,y+n+1,cmp);
	int ans=0;
	for(int i=1;i<=m-1;i++){
		ans = (y[i].c & y[i+1].c);
	}
	cout << ans; 
	return 0;
}
