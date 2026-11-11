#include<bits/stdc++.h>
using namespace std;
long long d,c,n,t,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		if (n==2){
			cout<<0<<endl;
			continue;
		}
		sort(a+1,a+n+1);
		long long p=a[2]-a[1],flag=0;
		for (int i=3;i<=n;i++)
			if (a[i]-a[i-1]!=p){
				flag=1;
				break;
		}
		if (flag==0){
			if (d<p){
				cout<<0<<endl;
				continue;
			} 
			int i,sum;
			for (i=1;i<=n;i++)
				if (a[i]>a[1]+d)
					break;
			if (a[1]+d>=a[n]){
				sum=n-2;
			}	
			else{
			i--;
			if (i-2>0)
				i-=2;
			else{
				cout<<0<<endl;
				continue;
				}
			}
			cout<<n-2<<endl;
		}
	}
	return 0;
}
