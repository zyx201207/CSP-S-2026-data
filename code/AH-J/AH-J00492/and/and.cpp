#include<bits/stdc++.h>
using namespace std;
int N,M,bitMAX;
long long A[200010];
int f[200010][33];
bool tf[200010],flag[200010];
long long pow(int x){
	if(x==-1) return 1;
	long long res=2;
	while(x>0){
		res*=2;
		x--;
	} 
	return res;
}
void init(){
	for(int i=1;i<=N;i++)
		flag[i]=tf[i];
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%lld",&A[i]);
		int j=0;
		while(A[i]>0){
			long long p=2;
			if(A[i]%p==1){
				f[i][j]=1;
				A[i]-=1;
			}
			A[i]>>=1;
			j+=1;
		}
		bitMAX=max(bitMAX,j);
	}
	bool ifa=false;
	long long ans=0;
	for(int j=bitMAX;j>=0;j--){
		memset(tf,false,sizeof(tf));
		int sum=0;
		for(int i=1;i<=N;i++){
			if((flag[i]||!ifa)&&f[i][j]){
				sum++;
				tf[i]=true;
			}
		}	
		if(sum>=M){
			ans+=pow(j-1);
			ifa=true;
			init();
		}
	}
	printf("%lld",ans);
	return 0;
} 
