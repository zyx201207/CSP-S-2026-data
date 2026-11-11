#include<bits/stdc++.h>
using namespace std;
long long n,x,ans=-1,sum,m,s,e,w[100],f[200005],p;
bool a[200005][100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		p=0;
		while(x){
			if(x%2==1)
			a[i][p]=1;
			else{
				a[i][p]=0;
			}
			w[p]=w[p]+x%2;
			x/=2;
			
			p++;
		}
	}
	for(int i=32;i>=0;i--){
		if(w[i]>=m){
			ans=i;break;
		}
	}
	if(ans==-1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)if(a[i][ans]!=1)f[i]=1;
	for(int i=ans;i>=0;i--){
		e=0;
		for(int j=1;j<=n;j++){
			if(f[j])continue;
			if(a[j][i])
			e++;
		}
		if(e>=m){
			e=1;
			sum=sum+pow(2,i);
		}
		else e=0;
		if(e){
			for(int j=1;j<=n;j++){
				if(a[j][i]==0)f[j]=1;
			}
		}
	}
	cout<<sum;
	return 0;
}
