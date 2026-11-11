#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long mx,ma,an;
int n,k,one,two,three,ans;
bool fir=true,zero;
long long a[N];
void dfs(int x,long long ad,int xz){
	if(xz==k){
		mx=max(mx,ad);
		return;
	}
	if(x>n) return;
	if(n-x+1<k-xz) return;
	if(xz==0) dfs(x+1,a[x],xz+1);
	else dfs(x+1,ad&a[x],xz+1);
	dfs(x+1,ad,xz);
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=a[i-1]) fir=false;
		if(a[i]==0) zero=true;
		if(i==1) an=a[i];
		else an=an&a[i];
		ma=max(ma,a[i]);
		if(a[i]==1){
			one++;	
		}else if(a[i]==2){
			two++;
		}else if(a[i]==3){
			three++;
		} 
	}
	if(fir)mx=a[1];
	else if(k==n) mx=an; 
	else if(k==n-1){
		if(zero){
			bool h=false;
			for(int i=1;i<=n;i++){
				if(a[i]==0&&!h){
					continue;
					h=true;
				}else if(i==1) an=a[i];
				else an=an&a[i];
			}
			mx=an;
		}
	}else if(ma<4){
		if(three>=k) mx=3;
		else if(two>=k) mx=2;
		else if(one>=k) mx=1;
		else mx=0;
		if(one+three>=k&&mx<1) mx=1;
	}else if(n<=20||k==1||k==2) dfs(1,0,0);
	else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=k;i++){
			if(i==1) an=a[i];
			else an=an&a[i];
		}
		mx=an;
	}
	printf("%lld",mx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}