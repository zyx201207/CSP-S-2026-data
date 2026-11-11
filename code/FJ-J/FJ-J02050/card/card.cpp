#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<n;
	}else{
		cout<<n<<" "<<n;
	}
	return 0;
}
