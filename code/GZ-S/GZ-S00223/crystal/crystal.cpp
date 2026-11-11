//GZ-S00223 遵义市第四初级中学 王培祯
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		int mi=a[i],mid=i-1,k=m;
		cnt=1;
		while(k>0&&mid>=1){
			if(mi-a[mid]<=k){
				k=k-(mi-a[mid]);
				cnt++;
			}
			else{
				break;
			}
			if(k<mi-a[mid]){
				break;
			}
			mid--;
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
} 
