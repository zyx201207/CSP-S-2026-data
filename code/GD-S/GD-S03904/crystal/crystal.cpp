#include<bits/stdc++.h>
//1018996 rp++
using namespace std;
long long q[500305];
long long eb[500305];//energy
bool cmp(long long a, long long b){return a>b;}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++){
		long long ai;
		scanf("%lld",&ai);
		eb[i]=ai;
	}
	if(n>5000){
		for(int i=0;i<n;i++){
			if((eb[i]-eb[0])*(i+1)>=2*m){
				printf("%d",i);
				return 0;
			}
		}
		printf("%d",n);
	}
	sort(eb,eb+n,cmp);
	int ma=-1;
	for(int i=0;i<n;i++){
		//printf("%lld\n",eb[i]);
		q[i]=0;
		for(int j=i+1;j<n;j++){
			q[j]=q[j-1]+eb[i]-eb[j];
			//printf("%d\n",q[j]);
		}
		long long m1=m;int u=0;
		for(int j=i;m1-q[j]>=0&&j<n;j++,u++);
		ma=u>ma?u:ma;
	}
	printf("%d",ma);
	return 0;
} 
