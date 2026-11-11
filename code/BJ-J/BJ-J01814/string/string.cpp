#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200005];
char b[200005];

int n;
ll ans;

int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<=r){
		ll mn;
		int idn,idx;
		if(a[l]>=a[r]){
			mn=a[r];
			idn=r;
			idx=l;
		}else{
			mn=a[l];
			idn=l;
			idx=r;
		}
		if(b[l]!=b[r]){
			ans+=mn;
		}
		a[idn]=0;
		a[idx]-=mn;
		if(a[l]==0)	l++;
		if(a[r]==0)	r--;
	}
	cout<<ans;
	return 0;
}
