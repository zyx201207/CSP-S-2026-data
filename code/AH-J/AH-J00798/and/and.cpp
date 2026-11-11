#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(k==1){
		cout<<a[1];
		return 0;
	}
	if(k==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					mx=max(mx,a[i]&a[j]);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	int as=a[1];
	for(int i=2;i<=k;i++)
		as&=a[i];
	cout<<as;
	return 0;
}
