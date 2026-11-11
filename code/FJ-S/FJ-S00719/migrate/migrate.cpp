#include <bits/stdc++.h>
using namespace std;
int c,t;
int a[2000002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		bool flag=true;
		for(int i=1;i<=n;i++){
			a[i]=0;
			cin>>a[i];
		}
		int c=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=c) flag=false;
		}
		if(flag){
			int e=d/c;
			if(c>=d||(d>c&&d<c*2)){
				cout<<"0"<<endl;
			}
			else if(n<=e+1){
				cout<<"0"<<endl;
			}
			else{
				if(d%c==0&&n>=e+2){
				    if(e%2==1)
					cout<<2*(n-e-2)+1<<endl;
					else
					cout<<n-e-1<<endl;
				}
			}
		}
	}
	return 0;
}
