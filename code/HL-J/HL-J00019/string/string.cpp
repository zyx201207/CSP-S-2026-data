#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	int l=1,r=n;
	long long sum=0;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r]) sum+=a[l];
			l++,r--;
		}
		else{
			if(a[l]<a[r]){
				if(c[l]!=c[r]) sum+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				if(c[l]!=c[r]) sum+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}