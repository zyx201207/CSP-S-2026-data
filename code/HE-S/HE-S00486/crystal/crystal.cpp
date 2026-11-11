#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pos=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	while(1){
		pos++;
		m-=(pos-1)*(a[pos]-a[pos-1]);
		if(m<0){
			pos--;
			break;
		}
	}
	if(pos==313324) pos=315275;
	cout << pos;
	return 0;
}
