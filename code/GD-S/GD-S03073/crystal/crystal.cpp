#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],m1,ji,maxs=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		m1=m;
		ji=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]>m1){
				if(ji>maxs){
					maxs=ji;
				}
				break;
			}
			else{
				ji++;
				m1-=a[i]-a[j];
				if(j==1){
					if(ji>maxs){
					maxs=ji;
					}
				}
			}
		}
	}
	cout<<maxs;
	return 0;
}
