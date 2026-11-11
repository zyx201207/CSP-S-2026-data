#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N];
char c[N];
long long tot;
int l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				tot+=a[l];
				a[r]-=a[l];
			}
			++l;
		}
		else if(a[l]==a[r]){
			if(c[l]!=c[r]) tot+=a[l];
			++l,--r;
		}
		else{
			if(c[l]!=c[r]){
				tot+=a[r];
				a[l]-=a[r];
			}
			--r;
		}
	}
	cout<<tot;
	return 0;
}
