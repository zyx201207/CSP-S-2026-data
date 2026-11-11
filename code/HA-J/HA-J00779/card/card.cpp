#include<bits/stdc++.h>
using namespace std;
long long n,m,t,b[500005],c[500005],sum;
struct xgt{
	long long id,ds;
}a[500005];
long long cmp(xgt a,xgt b){
	return a.id <b.id ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].ds ;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		sort(a+i,a+n+1,cmp);
		for(int j=i;j<=n;j++){
			for(int q=1;q<=sum;q++){
				if(b[q]==a[j].ds )
				{
					for(int p=q;p<=sum;p++){
						b[p]=0;
					}
					break;
				}
			}
			sum++;
			b[sum]=a[j].ds ;
		}
		for(int j=1;j<=sum;j++){
			c[b[j]]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
