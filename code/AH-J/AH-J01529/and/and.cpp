#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int t=1;
	for(int i=1;i<=30;i++)t*=2;
	for(int i=30;i>=0;i--,t/=2){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!f[j]&&(a[j]&t)>0)
				cnt++;
		}	
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!f[j]&&(a[j]&t)==0)
					f[j]=1;
			}
			ans|=t;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

