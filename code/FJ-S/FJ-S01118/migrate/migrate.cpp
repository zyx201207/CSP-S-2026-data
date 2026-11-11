#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
long long cnt;
bool sj(int a,int b){
	if(a-b==3&&x[b]-x[a]>d&&x[b-1]-x[a]<=d&&x[b]-x[a+1]<=d) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		cnt=0;
		scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(sj(i,j)){
					cnt++;
				}
			}
		}
		printf("%lld\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
