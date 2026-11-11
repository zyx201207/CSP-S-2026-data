#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k[35][200005];
ll a[200005],l,r,ans,p[35];
int flag[200005];
void power(int x){
	for(int i=1;i<=x;i++){
		p[i]=p[i-1]*2;
	}
}
int check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(flag[i]==l) cnt++;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		int num=0;
		ll b=a[i]; 
		while(b){
			if(b%2){
				k[num][++k[num][0]]=i;
			}
			num++;
			b/=2;
		}
	}
	for(int i=0;i<=30;i++){
		if(k[i][0]<m) k[i][0]=0;
		if(k[i][0]) r=max(r,i*1LL);
	}
	p[0]=1;
	power(r);
	l=0;
	for(int i=r;i>=0;i--){
		l++;
		for(int j=1;j<=k[i][0];j++){
			flag[k[i][j]]++;
		}
		int kk=check();
		if(kk<m){
			for(int j=1;j<=k[i][0];j++){
				flag[k[i][j]]--;
			}
		} 
		else ans+=p[i];
	}
	printf("%lld",ans);
	return 0;
}
