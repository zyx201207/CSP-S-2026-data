#include<bits/stdc++.h>
using namespace std;
long long a[10000005],n,m,f=0,i,j;
long long b[10000005];
long long flag[10000005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	int t=n;
	int l=1;
	while(t--){
		int r=1;
		b[r]=a[l];
		r++;
		for(i=l+1;i<=n;i++){
			f=0;
			for(j=1;j<r;j++){
				if(a[i]==b[j]){
					r=r-j;
					f=1;
					break;
				}
			}
			if(f==1){
				continue;
			}else{
				b[r]=a[i];
				r++;
			}
		}
		for(int i=1;i<r;i++){
			flag[b[i]]++;
		}
		l++;
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",flag[i]);
	}
}
