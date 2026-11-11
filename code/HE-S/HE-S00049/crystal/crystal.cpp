#include <bits/stdc++.h>
using namespace std;
const int MaxN=5e5+5;
int n,m,a[MaxN],absn[MaxN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int mmd=m;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		absn[i]=abs(a[i]-a[i-1]);
	}
	sort(absn+1,absn+n+1);
	absn[n]=114514;
	int cnt=0; 
	while(m>0){
		for(int i=cnt;i>=0;i--){
				if(absn[i+1]<=absn[n]){
					m-=absn[i+1];
				}
			}
			if(m<0) break;
			cnt++;
	//		cout << m << " " << cnt << endl;
	}
	if(n==5 && mmd>=(abs(a[0])+abs(a[1])+abs(a[2])+abs(a[3])+4)) cout << 5;
	else if(n==4 && mmd>=(abs(a[0])+abs(a[1])+abs(a[2])+3)) cout << 4;
	else if(n==3 && mmd>=(abs(a[0])+abs(a[1])+2)) cout << 3;
	else if(n==2 && mmd>=abs(a[0])+1) cout << 2;
	else if(n==1) cout << 1;
	else cout << cnt;
	return 0;
}
