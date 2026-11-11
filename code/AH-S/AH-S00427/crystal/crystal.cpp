#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,a[N],b[N],ans,mn=1e9;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i-1];
		mn=min(b[i],mn);
	}
	for(int i=0;i<n-1;i++){
		long long mm=m,cnt=1;
		for(int j=i+1;j<n;j++){
			if(mm<b[j]*(j-i)){
				break;
			}
			mm-=b[j]*cnt;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
