#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char b[200010];
ll a[200010],n;										
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	ll z=1,y=n,he=0;
	while(z<y){
		ll p=min(a[z],a[y]);
		if(b[z]!=b[y]) he+=p;
		a[z]-=p;
		a[y]-=p;
		if(!a[z]) z++;
		if(!a[y]) y--;
	}
	cout<<he;
	return 0;
}
