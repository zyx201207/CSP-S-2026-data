#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[410000],l,r,cnt;
char c[410000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			cnt+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else{
			l++;r--;
		}
	}
	cout<<cnt;
	return 0;
}
