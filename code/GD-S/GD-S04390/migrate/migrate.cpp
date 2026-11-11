#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	int q=0;
	while(t--){
		cin>>n>>d;
		for(int i =1;  i<= n ; i ++){
			cin>>a[i];
		}
		q++
		cout<<q;
		
	}
	
}
