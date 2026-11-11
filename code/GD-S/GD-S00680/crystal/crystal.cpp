#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=1,pre[500010];
long long a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int j=maxn;
		for(;j<=i-1;j++){
			if(m-a[i]*j+(pre[i-1]-pre[i-j-1])<0){
				//cout<<"I have break\n";
				break;
			}
			//cout<<"i: "<<i<<" j: "<<j<<' '<<a[i]<<' '<<pre[i-1]-pre[i-j-1]<<' '<<a[i]*j-(pre[i-1]-pre[i-j-1])-m<<'\n';
		}
		maxn=j;
	}
	cout<<maxn<<'\n';
	return 0;
}
