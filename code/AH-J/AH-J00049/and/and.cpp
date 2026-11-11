#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans,f[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=1;
	}
	for(int i=29;i>=0;i--){
		int t=(1<<i),s=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=t&&f[i]==1) s++;
		}
		if(s>=m){
			for(int i=1;i<=n;i++){
				if(f[i]==1){
					if(a[i]<t) f[i]=0;
					else{
						a[i]-=t;
					}
				} 
			}
			ans+=t;
		}
	}
	cout<<ans;
	return 0;
}
