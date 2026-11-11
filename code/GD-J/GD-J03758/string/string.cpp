#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+5;
long long n,a[maxn],pre[maxn],cnt;
char c[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		pre[i]=pre[i-1]+a[i];
	}
	long long l=1,r=pre[n],x=1,y=n;
	while(l<r){
		if(l>pre[x])	x++;
		if(r<=pre[y-1])	y--;
		if(c[x]!=c[y])	cnt++;
		l++;
		r--;
	}
	cout<<cnt<<'\n';
	return 0;
} 
