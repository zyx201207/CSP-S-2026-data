#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n,d;
	int c,t;
	cin>>c>>t;
	
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long s=d*2-1;
		int j=1;
		while(s-(a[2]-a[1])>=0 && j<=n){
			s-=(a[2]-a[1]);
			j++;
			//cout<<j<<' '<<s<<endl;
		}
		int k=j;
		cout<<n-k+1<<endl;
	}
	
	
	return 0;
}

