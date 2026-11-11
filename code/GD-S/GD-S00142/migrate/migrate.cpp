#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		long long n,d,q=0,sum=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if((a[i]-a[1]<=d))q=i;
		}
		int r=a[2]-a[1];
		if(d==0){
			cout<<0;
		}
		else{
			for(int i=1;i<=n;i++){
				int e=2;
				for(int j=i+3;j<=n;j++){
					if((j-i)/e==q+1||(j-i)/e==q-1){
						e++;
						sum++;
					}
				}	
			}
		}
		cout<<sum;
	}
	return 0;
}
