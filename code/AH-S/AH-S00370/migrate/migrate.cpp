#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int x=0;
		bool f=1;
		int cnt=2;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1||i==2){
				x=a[i]-a[i-1];
			}
			else if(!(a[i]-a[i-1]==x&&f)){
				f=0;
			}
		}
		if(m==1||n<2*m){
			cout<<0;
		}
		else if(f){
			cout<<n-2*m+1;
		}
		else{
			cout<<n-2*m-1;
		}
		cout<<endl;
	}
	return 0;
}
