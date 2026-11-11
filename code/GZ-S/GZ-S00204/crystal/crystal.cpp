//GZ-S00204 何奇峰宇 北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

int n,m,a[N],c[N],l[N],r[N],ans,cnt;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool f=1;
	for(int i=1;i<=n;i++){
		c[i-1]=a[i]-a[i-1];
	}
	for(int i=2;i<n;i++){
		if(c[i]!=c[i-1]) f=0;
	}
	if(f==1){
		vector<int> sum(n);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+(c[1]*i);
			if(sum[i]<=m){
				ans=max(ans,i+1);
			}
			else{
				cout<<ans;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int li=i,ri=i;
		while(li>1){
			li--;
			l[i]+=1ll*c[li]*li;
		}
		int t=n-i+1;
		while(ri<n){
			--t;
			r[i]+=1ll*c[ri]*t;
			ri++;
		}
	}
	for(int i=1;i<=n;i++){
		int ansi=INT_MIN;
		if(l[i]<=m){
			ansi=i;
		}
		if(r[i]<=m){
			ansi=max(ansi,(n-i));
		}
		ans=max(ans,ansi);
	}
	cout<<ans;
	return 0;
}
