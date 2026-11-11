#include<bits/stdc++.h>
using namespace std;
long long n,m,b[500005],l,r;
long long a[500005],cnt,jz,ans,maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	jz=a[n];
	for(int i=n,j=n;i>=1;i--){
		cnt+=(jz-a[i]);
		ans++;
		while(cnt>m){
			j--;
			ans--;
			cnt-=ans*(jz-a[j]);
			jz=a[j];
		}
		maxn=max(ans,maxn);
	}
	cout<<maxn<<endl;
	
	return 0;
}
