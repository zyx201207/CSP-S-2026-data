#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,maxp,ans;
bool a[N][35],ok[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int b=1,e=0;
		while(b<=x)	b*=2,e++;
		e--,b/=2;
		maxp=max(maxp,e);
		while(x&&e>=0){
			if(x>=b) a[i][e]=1,x-=b;
			b/=2,e--;
		}
		//for(int j=0;j<=30;j++) cout<<a[i][j];
		//cout<<'\n';
	}
	int b=1;
	for(int i=1;i<=maxp;i++) b*=2;
	for(int i=maxp;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++) if(ok[j]==0&&a[j][i]==1) cnt++;
		if(cnt>=m){
			ans+=b;
			for(int j=1;j<=n;j++) if(a[j][i]==0) ok[j]=1;
		}
		b/=2;
	}
	cout<<ans;
    return 0;
}
