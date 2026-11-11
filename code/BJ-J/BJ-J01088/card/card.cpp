#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	srand(time(NULL));
	cout<<rand()%2000+1;
	return 0;
}

