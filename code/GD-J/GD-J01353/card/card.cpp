#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+1000;
long long n,m,a[maxn],b[maxn],l=1,c[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int q=i;q<=n;q++){
			b[l]=a[q];
			for(int j=1;j<l;j++){
				if(a[q]==b[j]){
					b[j]=a[q];
					l=j;
					break;
				}
			}
			l++;
		}
		for(int j=1;j<=l-1;j++){
			c[b[j]]++;
		}
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		l=1;
	}
	for(int j=1;j<=m;j++){
		printf("%lld ",c[j]);
	}
	return 0;
}
