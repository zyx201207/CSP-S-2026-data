#include<bits/stdc++.h>
using namespace std;
long long a[202020],b[202020],n,ans;
char op;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&op);
		b[i]=op-'a'+1;
	}
	for(int l=1,r=n;l<r;){
		if(a[l]<a[r]){
			if(b[l]!=b[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		else if(a[l]>a[r]){
			if(b[l]!=b[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else{
			if(b[l]!=b[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
