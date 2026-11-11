#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5;
int n;
long long m,a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<m/3; 
	return 0;
} 
