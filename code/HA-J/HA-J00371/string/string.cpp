#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,m,sum;
int a[N];
char c[N],s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
			if(a[l]==a[r]){
				if(c[l]!=c[r]) sum+=a[l];
				a[l]=a[r]=0;
				l++,r--;
			}
			else if(a[l]>a[r]){
				if(c[l]!=c[r]) sum+=a[r];
				a[l]-=a[r],a[r]=0;
				r--;
			}
			else{
				if(c[l]!=c[r]) sum+=a[l];
				a[r]-=a[l],a[l]=0;
				l++;
			}
	}
	cout<<sum<<endl;
	return 0;
}

