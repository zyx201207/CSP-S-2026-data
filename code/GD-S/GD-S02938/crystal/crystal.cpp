#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],b[N],maxx=INT_MIN,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int k=m; sum=1;
		for(int j=i+1;j<=n;j++){
			if(abs(a[j]-a[i])<=k){
				sum++;
				k=k-abs(a[j]-a[i]);
			}else{
				break;
			}
		}
		maxx=max(maxx,sum);
	}
	for(int i=n;i>0;i--){
		int k=m; sum=1;
		for(int j=n;j>0;j++){
			if(abs(a[i]-a[j])<=k){
				sum++;
				k=k-abs(a[i]-a[j]);
			}else{
				break;
			}
		}
		maxx=max(maxx,sum);
	}
	printf("%d",maxx);

	return 0;
}
