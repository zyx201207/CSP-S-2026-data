#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
//		cout<<d<<" "<<(x[2]-x[1])<<" ";
		d=d/(x[2]-x[1]);
		if(d==0||d==1)cout<<"0\n";
		else cout<<max(0ll,n-(d*2-1))<<"\n";
	}
	
	
	return 0;
}







/*
17:02赶紧看T3 

来不及想正解了，先写暴力吧 

。。。咋写啊 
额，好像不会
特殊性质吧 
。只会A
8pts 
*/
