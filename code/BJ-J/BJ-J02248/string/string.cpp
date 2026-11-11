#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	long long ans=0,sum=0,w=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
		sum+=a[i];
	}
	int l=1,r=n;
	while(r>l){
		if(a[l]>a[r]){
			w+=a[r];
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else{
			if(a[l]<=a[r]){
				w+=a[r];
				if(c[l]!=c[r]){
					ans+=a[l];
				}
				a[r]-=a[l];
				l++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
