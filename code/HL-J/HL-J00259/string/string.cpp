#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[100010],r=0,l=1,ans=0,L=0;
	char c[100010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	L=r+1;
	while(l<=r){
		long long ll=l,rr=L-r;
		long long lll,rrr;
		for(int i=1;i<=n;i++){
			if(ll<=a[i]){
				lll=i;
				break;
			}else {
				ll-=a[i];
			}
		}
		for(int i=n;i>=1;i--){
			if(rr<=a[i]){
				rrr=i;
				break;
			}else {
				rr-=a[i];
			}
		}
		if(c[lll]!=c[rrr]){
			ans++;
		}
		l++;
		r--;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
