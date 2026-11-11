#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int ans=1;
int tot;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=abs(a[2]-a[1]);
	tot=cnt;
	if(m==cnt){
		cout<<2;
		return 0;
	}
	while(m>0){
		if(m-tot<0){
			break;
		}
		m-=tot;
		ans++;
		tot+=cnt;
	}
	cout<<ans;
	return 0;
}
//数据水一点，求你了qwq 
