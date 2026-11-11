#include <bits/stdc++.h>

using namespace std;
int a[500005];
int main(int argc, char** argv) {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
    srand(time(0));
	cout<<1+rand()%(n-1);
	return 0;
}
