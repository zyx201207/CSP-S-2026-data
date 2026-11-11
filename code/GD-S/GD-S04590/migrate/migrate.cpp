#include<bits/stdc++.h>
using namespace std;
const int N=2000100;
int c,t,n,ans;
long long a[N];
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		ans=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
		} 
		ans=max(n-d-d+1,0);
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 3
2 3 4 5 6

*/
/*
5 5
1 2 4 8 9

*/
