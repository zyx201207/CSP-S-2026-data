//GZ-S00149 兴义市弘毅中学 廖颢云
#include <bits/stdc++.h>
using namespace std;
long long n,m,sumn;
long long a[500005],b[500005],c[500005];
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 2;i <= n;i++){
		b[i-1] = abs(a[i] - a[i-1]);
	}
	sort(b+1,b+n);
	c[1] = b[1];
	for(int i = 1;i <= n-1;i++){
		c[i] = b[i] + c[i-1];
	}
	for(int i = 1;i <= n-1;i++){
		if(m - c[i] >= 0){
			sumn++;
			//m -= c[i];
			if(c[i] == 0)sumn++;
		}else{
			break;
		}
	}
	cout << sumn;
	return 0;
}
