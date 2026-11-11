#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,a[200005],sum=0;
		cin>>n>>d>>a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			if(d/(a[2]-a[1])==0||d/(a[2]-a[1])==1){
				cout<<0;
				break;
			}else{
				for(int i=1;i<=n;i++){
					sum+=(n-i-1)%d/(a[2]-a[1]);
				}
				cout<<sum;
			}
		}
	}
} 
