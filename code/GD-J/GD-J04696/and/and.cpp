#include<bits/stdc++.h>
using namespace std;
bool f[200000],fi1,f2n;
int n,m;
long long mx=-1,anda,n2=2,a[200000];
void dfs(int step,int ii,long long s){
	if(step==m){
		mx=max(mx,s);
		return;
	}
	for(int i=ii;i<n;i++){
		if(!f[i]){
			f[i]=true;
			if(step==0){
				dfs(step+1,i+1,a[i]);
			}
			else{
				dfs(step+1,i+1,s&a[i]);
			}
			f[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(i==0){
			anda=a[i];
		}
		else{
			anda&=a[i];
		}
		if(a[i]!=i){
			fi1=true;
		}
		if(a[i]!=n2-1){
			f2n=true;
		}
		else{
			n2*=2;
		}
	}
	if(m==n){
		printf("%lld",anda);
		return 0;
	}
	if(!f2n){
		printf("%lld",a[n-m]);
		return 0;
	}
	if(!fi1){
		printf("%lld",n-m);
		return 0;
	}
	mx=-1;
	dfs(0,0,0);
	printf("%d",mx);
	return 0;
} 
