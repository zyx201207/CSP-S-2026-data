#include<bits/stdc++.h>
using namespace std;
int t,a[2000005],c,n,d,s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		s=0;
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i+1]<=d&&a[i+3]-a[i+2]<=d&&a[i+3]-a[i]>d){
				s++;
			}
		}
		printf("%d\n",s);
	}
	
	return 0;
} 
