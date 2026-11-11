#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long cnt=0,s=0;
		for(int j=i;j>=1;j--){
			s+=a[i]-a[j];
			if(s>m)
				break;
			cnt++;
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
}
