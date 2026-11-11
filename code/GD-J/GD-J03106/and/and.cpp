#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long n,m,a[20005],ma=-2147483647;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long cnt=a[i];
		for(int j=i;j<=n;j++){
			for(int k=j;k<=m+j;k++){
				if(k+1<=n)cnt&=a[k+1];
			}
		}
		ma=max(ma,cnt);
	}
	cout<<ma;
	return 0;
}
