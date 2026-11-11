#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int g=1;g<=t;g++){
		long long n,d,cnt=0;
		long long a[100001];
		long long q[100001];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(a[i]>=a[j]){
						q[++cnt]=a[i]-a[j];
					}
					else q[++cnt]=a[j]-a[i];
				}
			}
		}
		int kg=0;
		for(int i=2;i<=cnt;i++){
			if(q[i-1]!=q[i]){
				kg=1;
			}
		}
		cout<<0;
	}
}
