#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n;
ll a[N],d[N];
ll f[N],t,s,m,sum;
bool flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	int x,y=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>1&&x!=a[i]-y){
			flag=0;
		}
		x=a[i]-y;
		y=a[i];
	}
	if(flag){
		for(int i=n;i>=2;i--){
			sum=(1+i)*x/2;
			if(sum<=m){
				printf("%d\n",i);
				return 0;
			}
		}
	}
	for(int i=1;i<=n-1;i++){
		t=t-a[i];
		t=t+a[n];
	}
	a[n+1]=a[n];		
	sort(a+1,a+n+1);
	for(int R=n;R>=1;R--){
		t=t+R*(a[R]-a[R+1]);
		s=t;
//		printf("%lld\n",t);
		for(int l=1,r=R;r<=n;l++,r++){
			if(l>1){
				s=s+(R-1)*(a[r]-a[r-1])-a[r-1]+a[l-1];
			}
			if(s<=m){	
				printf("%d\n",R);
				return 0;
			}
		}
	}
}