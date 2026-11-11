#include<bits/stdc++.h>
using namespace std;

int a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,len=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int res=1;
	for(int i=2;i<=n;i++){
		int w=len*(a[i]-a[i-1]);
		while(w>m){
			m+=a[i-1]-a[i-len];
			w=(--len)*(a[i]-a[i-1]);
		}
		m-=w;
		len++;
		res=max(res,len);
	}
	cout<<res;
	return 0;
}
