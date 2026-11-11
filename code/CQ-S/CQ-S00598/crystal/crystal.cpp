#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],m,x,zym,y;
queue<long long> shanshan;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	*cin.tie(nullptr)<<fixed<<setprecision(20);
	cout.tie(nullptr)->ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(int i=1;i<=n;++i){
		y+=x*(a[i]-a[i-1]);
		++x;
		shanshan.push(a[i]);
		while(y>m){
			y-=a[i]-shanshan.front();
			--x;
			shanshan.pop(); 
		}
		zym=max(zym,x);
	}
	cout<<zym;
	return 0;
}

