#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000010],m[5001][5001];
void f(){
	if(n<=3){
		return ;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(a[j]-a[i]>d){
				for(int k=i+1;k<j;k++){
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
						m[i][j]++;
						if(m[i][j]>=3){
							break;
						}
					}
				}
			}
		}
	}
}
int main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(m,0,sizeof(m));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		f();
		int s=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(m[i][j]==2){
					s++;
				}
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}
