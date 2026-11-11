#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N], s[N], ma[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	int xx = 0;
	bool cc = 1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i==2){
			xx = a[i] - a[i-1];
		}
		if(i>=3){
			if(a[i] - a[i-1] != xx){
				cc = 0;
			}
		}
	}
	sort(a+1,a+n+1);
	memset(s,-0x3f,sizeof(s));
	if(cc == 1){
		cout << m/xx/2;
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			s[i] = a[i];
		}
		else{
			s[i] = s[i-1] + a[i];
		}
		for(int j=1;j<=n;j++){
			long long zz = (s[i]*2 - s[i-j]*16 + a[i]*2)/3;
			if((zz>m)&&(ma[j]==0)){
				ma[j] = (s[i]*2 - s[i-j]*16 + a[i]*2)/3;
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(ma[i]<0){
			cout << i << '\n';
			return 0;
		}
	}
	return 0;
}
