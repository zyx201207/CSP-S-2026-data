#include<bits/stdc++.h>
using namespace std;

int c,t,x[1000001],num[1000001];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			num[j]=num[j-1]+(x[j]-x[j-1]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int hg=num[k]-num[j];
				if(hg>d&&(hg%d!=0)){
					//cout<<hg<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		for(int j=1;j<=n;j++){
			num[j]=0;
		}
	}
	return 0;
}
