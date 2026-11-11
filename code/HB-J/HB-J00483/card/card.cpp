#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N]={0};
int main(void){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=0;
	int now=a[1],ans=1;
	for(int i=2;i<=n+1;i++){
		if(now==a[i]){
			ans++;
		}else{
			cout<<ans<<' ';
			now=a[i];
			ans=1;
		}
	}
	return 0;
}
