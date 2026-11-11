#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,a[2000005],sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				else sum++;
			}
		}
		cout<<sum<<endl;
	} 
	return 0;
}

