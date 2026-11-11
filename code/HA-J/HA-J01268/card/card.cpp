#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i<=1;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
