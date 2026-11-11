//GZ-J00215    贵州省瓮安第二中学    卢浩宇
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,rzhi=0,lzhi=0,ans=0;
ll a[200005];
char zimu[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n; 
	for(int i=0;i<n;i++){
		cin>>a[i]>>zimu[i];
	}
	rzhi=n-1;
	while(lzhi<rzhi){
		if(a[lzhi]==0){
			lzhi++;
		}
		if(a[rzhi]==0){
			rzhi--;
		}
		if(zimu[lzhi]!=zimu[rzhi]){
			int awm=min(a[lzhi],a[rzhi]);
			a[lzhi]-=awm;
			a[rzhi]-=awm;
			ans+=awm;
		}
		if(zimu[lzhi]==zimu[rzhi]){
			int awm=min(a[lzhi],a[rzhi]);
			a[lzhi]-=awm;
			a[rzhi]-=awm;
		}
	}
	cout<<ans;
	return 0;
}
