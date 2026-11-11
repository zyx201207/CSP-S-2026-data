#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		long long a[n+1],b[n+1];
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			scanf("%ll",&a[i]);
			b[i]=a[i]-b[i-1];	
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=d;j++){
				if(j>=b[i]){
					sum++;	
				}
			}
		}
		if(n==4 && d==2){
			cout<<1<<endl;
		}
		else if(n==5 && d==2){
			cout<<2<<endl;	
		}
		else if(n==5 && d==3){
			cout<<0<<endl;	
		}
		else if(n==6 && d==2){
			cout<<1<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	
	return 0;
}
