#include <bits/stdc++.h>
using namespace std;
const int N=1e6*5+5;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		int n,d,cnt=0;
		int a[N]={};
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int l=2*d-1;
		for(int i=n;i>0;i++){
			for(int j=1;j<=i-2;j++){
				if((a[i]-a[j])==l){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
} 
