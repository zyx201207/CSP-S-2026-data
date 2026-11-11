#include <bits/stdc++.h>
using namespace std;

const int MAXN=5e5+5,MAXM=3e5+5;

int n,m;
int a[MAXN],lst[MAXM],num[MAXM];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	
	for (int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
		num[a[i]]++;
	}
	
	if (m==1) {cout<<n;return 0;}
	if (m==2) {
		if (a[n]==1) cout<<n<<' '<<num[2];
		else cout<<num[1]<<' '<<n;
		return 0;
	}
	for (int i=1;i<=m;i++)
		cout<<lst[i]<<' ';
	
	return 0;
}
