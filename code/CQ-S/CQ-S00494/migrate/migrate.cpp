#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,failed=0,n,d,ans,dis=0;
	scanf("%d %d",&c,&t);
	while(t--) {
		failed=0;
		ans=0;
		scanf("%d %d",&n,&d);
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		failed+=(n-1);
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(j-i==1){
					continue;
				}
				dis=abs(a[j]-a[i]);
				if(dis%d==0){
					failed++;
					continue;
				}
				/*
				6:4+2;2+4;3+3;
				3:1+2;2+1;
				5:3+2;2+3; 
				8(5):5+3;3+5;4+4;
				8(3):3+3+2;2+3+3;3+3+2;
				*/
				if(dis>d*2){
					failed++;
					continue;
				}
				if(dis%2==0) {
					failed++;
					continue;
				}
				if((dis+1)/2!=d){
					failed++;
					continue;
				}
			}
		}
		printf("%d\n",n*(n-1)/2-failed);
	}
	return 0;
}

