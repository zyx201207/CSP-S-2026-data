#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long m,M,ans,Max,p,mol;
struct rec{
	long long na,num,NA;
}a[500010];
bool cmp(rec x,rec y){
	return x.na<y.na; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].na);
	}
	sort(a+1,a+n+1,cmp);
	a[1].NA=a[1].na;
	a[1].num=1;
	cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i].na==a[i-1].na){
			a[cnt].num++;
		}
		else{
			cnt++;
			a[cnt].NA=a[i].na;
			a[cnt].num++;
		}
	}
	for(int i=2;i<=cnt;i++){
		Max=0,M=m;
		for(int j=i-1;j>=1;j--){
			p=a[i].NA-a[j].NA;
			if(p>M){
				continue;
			}
			if(M>=p*a[j].num){
				M-=p*a[j].num;
				Max+=a[j].num;
			}
			else{
				
				mol=M/p;
				Max+=mol;
				continue;
			}
		}
		Max+=a[i].num;
		ans=max(ans,Max);
//		printf("%lld %lld\n",ans,Max);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
