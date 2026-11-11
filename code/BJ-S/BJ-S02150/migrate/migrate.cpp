#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
const int Max=2e6+10;
int a[Max];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[n]-a[1]<d){
			int cnt=0;
			for(int i=n-2;i>1;i--){
				cnt+=i;
			}
			cout<<cnt<<endl;
		}
		else{
			int cnt=0;
			for(int i=d-2;i>1;i--){
				cnt+=i;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
