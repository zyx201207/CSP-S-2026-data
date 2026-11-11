#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+5;
int n,m,ans;
int a[N];

bool cmp(int aa,int bb){
	return aa>bb;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i))cnt++;
			else break;
		}
		if(cnt>=m){
			for(int j=1;j<=cnt;j++){
				a[j]&=(1<<i)-1;
			}
			n=cnt;
			ans|=(1<<i);
			sort(a+1,a+n+1,cmp); 
		}else{
			for(int j=1;j<=n;j++){
				a[j]&=(1<<i)-1;
			}
			sort(a+1,a+n+1,cmp);
		}
	}
	cout<<ans;
	return 0;
}
