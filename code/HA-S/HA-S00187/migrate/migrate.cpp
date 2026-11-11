#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,p=0,q=0;
	bool ok=0;
	cin>>c>>t;
	for (int g=1;g<=t;g++){
		cin>>n>>d;
		sum=0;
		p=0;
		q=0;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			if(a[i]-1==a[i-1] && ok==0){
				p=i-1;
				ok++;
			}
			else if(ok==1) q=i-1;
		}
		if(p!=0 && q==0){
			q=n;
		}
		if(q-p<=d){
			cout<<0<<endl;
			continue;
		}
		for (int i=p+1;i<=q;i++){
			sum+=a[i]-a[i-1];
		}
		cout<<sum/d<<endl;
	}
	return 0;
}
