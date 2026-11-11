#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;

int n,m;
int an[N];
int bn[N];
int cn[N];
int dn[N];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>an[i];
		bn[an[i]]=i;
	}
	int dq=1;
	while(dq<=n){
		for(int i=dq;i<=n;i++){
			dn[an[i]]++;
			i=bn[an[i]];
		}
		dq++;
	}
	for(int i=1;i<m;i++) cout<<dn[i]<<" ";
	cout<<dn[m];
	return 0;
}

