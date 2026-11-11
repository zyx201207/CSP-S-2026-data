#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10001],sum;
bool b[10001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i = 1;i<=n;i++){
			sum = max(sum,a[i]);
		}
		printf("%d",sum);
	}
	if(m==2){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i!=j){
					sum = max(sum,a[i]&a[j]);
				}
			}
		}
		printf("%d",sum);
	}
	return 0;
}
