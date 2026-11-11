#include<bits/stdc++.h>
using namespace std;
int n,x[200005];
char y[200005];
long long s=0;
int main(){
	freopen("xx.in","r",stdin);
	freopen("xx.out","w",stdout);
	ios::sync_with_stdio(0); cin .tie(0); cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i];
		s+=x[i];
	}
	int l=1,r=n,a=1,b=x[n];
	long long ans=0;
	s/=2;
	while(s--){
		if(y[l]!=y[r]){
			ans++;
		}
		a++;
		b--;
		if(a>x[l]){
			l++;
			a=1;
		}
		if(b==0){
			r--;
			b=x[r];
		}
	}
	cout << ans;
	return 0;
}
