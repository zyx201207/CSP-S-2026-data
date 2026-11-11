#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2*1e5 + 10;
int n;
int  a[N];
char c[N];
int p1,p2,mint;
ll ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	p1 = 1,p2 = n;
	while(p1 < p2){
		mint = min(a[p1],a[p2]);
		if(c[p1] != c[p2]){
			ans += mint;
		}
		a[p1]-=mint;
		a[p2]-=mint;
		if(a[p1] == 0) p1++;
		if(a[p2] == 0) p2--;
	}
	cout<<ans;
	return 0;
}
