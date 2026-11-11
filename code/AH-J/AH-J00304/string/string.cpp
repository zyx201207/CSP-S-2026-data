/*
CCF将对所有考生程序查重
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
