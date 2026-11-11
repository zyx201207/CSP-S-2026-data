#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
long long m,a[500005],st[500005][15];
long long function1(int l,int r){
	int i=0;
	while(((1<<i)-1)<=(r-l)) i++;
	i--;
	long long sum=st[l][i];
	for(int j=i-1,k=l+(1<<i);j>=0&&k<=r;j--){
		//printf("*");
		if(k+(1<<j)-1<=r){
			if(st[k][j]==-1){
				return -1;
			}
			if(m-st[k][j]-sum<(a[k+(1<<j)-1]-a[k-1])*(k-l)){
				return -1;
			}
			sum=sum+st[k][j]+(a[k+(1<<j)-1]-a[k-1])*(k-l);
			k+=(1<<j);
		}
	}
	return sum;
}
int max(int a1,int a2){
	if(a1>a2){
		return a1;
	}else{
		return a2;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	} 
	sort(a+1,a+1+n);
	/*for(int i=1;i<n;i++){
		st[i][0]=a[i+1]-a[i];
	}*/
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			if(st[j][i-1]==-1||st[j+(1<<(i-1))][i-1]==-1){
				st[j][i]=-1;
			}else if(m-st[j][i-1]-st[j+(1<<(i-1))][i-1]<(a[j+(1<<i)-1]-a[j+(1<<(i-1))-1])*((1<<(i-1)))){
				st[j][i]=-1;
			}else{
				st[j][i]=st[j][i-1]+st[j+(1<<(i-1))][i-1]+(a[j+(1<<i)-1]-a[j+(1<<(i-1))-1])*((1<<(i-1)));
			}
		}
	}
	//printf("%lld %lld %lld\n",a[2],a[3],a[4]);
	/*for(int i=0;(1<<i)<=n;i++){
		printf("%d ",i);
		for(int j=1;j+(1<<i)-1<=n;j++){
			printf("%lld ",st[j][i]);
		}
		printf("\n");
	}*/
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(i<j){
			i++;
		}
		while(function1(j,i)==-1){
			j++;
		}
		//printf("%lld %d %d\n",function1(j,i),j,i);
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
