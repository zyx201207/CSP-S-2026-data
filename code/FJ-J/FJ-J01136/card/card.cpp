#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
long long n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		long long x;
		scanf("%d",&x);
		a[x]++;
	}
	return 0;
}
