//GZ-J00242 北京师范大学贵阳附属中学 李培源
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=0;
//	long long q=0;
	for(int i=1;i<=n-m;i++){
		long long cnt=a[i]; 
		for(int j=1;j<m;j++){
//			q++;
			cnt=cnt&a[i+j];
		}
		if(cnt!=0){
			ans=cnt;
			break;
		}
//		ans=max(ans,cnt);
//		cout<<ans<<endl;
	}
//	cout<<q<<endl;
	cout<<ans;
	return 0;
} 
