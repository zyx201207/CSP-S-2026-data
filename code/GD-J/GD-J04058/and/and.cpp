#include<bits/stdc++.h>
using namespace std;
#define long long int
const int N=2e5+10;
int a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else{
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]<4)continue;
			else flag=0;
		}
		if(flag==0){
			cout<<a[m];
		}
		else{
			for(int i=1;i<=n;i++){
				b[a[i]]++;
			}
			int mx=-1;
			for(int i=1;i<=n;i++){
				if(b[a[i]]>=m){
					mx=max(mx,a[i]);
				}
			}
			if(mx==-1)cout<<0;
			else cout<<mx;
		}
	}
	return 0;
}
