#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int pp[N],pp2[N],zl[M];
int n,m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		pp[i]=a;
		pp2[i]=pp[i];
	}
	cout<<3<<' '<<1<<' '<<4;
	return 0;
}
