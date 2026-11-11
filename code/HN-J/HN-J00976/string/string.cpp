#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+10,INF=1e18;
struct P{
	int x;
	char y;
}a[N];
int n,id;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	int su=0;
	int l=1,r=n;
	while(l+1<=r){
		if(a[l].x>a[r].x){
			a[l].x-=a[r].x;
			if(a[l].y!=a[r].y){
				su+=a[r].x;
			}
			r--;
		}else if(a[l].x<a[r].x){
			a[r].x-=a[l].x;
			if(a[r].y!=a[l].y){
				su+=a[l].x;
			}
			l++;
		}else{
			if(a[l].y!=a[r].y){
				su+=a[r].x;
			}
			l++;
			r--;
		}
	}
	cout<<su;
	return 0;
}
