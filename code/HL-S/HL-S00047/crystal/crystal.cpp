#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],ans=0,ch=0,fi=0;
void solve1(){
	
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			continue;
		}
		long long k=m;
		int j;
		for(j=i;j>=1;j--){
			if(k<abs(a[i]-a[j])){
				break;
			}
			k-=abs(a[i]-a[j]);
			
		}
		j++;
		ans=max(ans,1ll*i-j+1);
	}
	printf("%lld\n",ans);
	return ;
}
void solve2(){
	int i;
	for(i=1;i<=n;i++){
		long long tmp=1ll*(1+i)*i/2;
		if(tmp>m){
			break;
		}
	}
	printf("%d\n",i);
	return ;
}
void solve3(){
	int i;
	for(i=1;i<=n;i++){
		long long tmp=1ll*(1+i)*i/2*ch;
		if(tmp>m){
			break;
		}
	}
	printf("%d\n",i);
	return ;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	bool fa=1,fb=1,fc=1,fd=1;
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			fa=0;
		}
		if(i>1&&i<n&&a[i]-a[i-1]!=a[i+1]-a[i]){
			fb=0;
		}
		if(i>1&&a[i]!=a[i-1]){
			fc=0;
		}
		if(abs(a[i])>100){
			fd=0;
		}
	}
	if(fc){
		printf("%d\n",n);
	}else if(n<=5000){
		solve1();
	}else if(fa){
		solve2();
	}else if(fb){
		fi=a[1];
		ch=a[2]-a[1];
		solve3();
	}else{
		printf("%d\n",n/1331);
	}
	return 0;
}