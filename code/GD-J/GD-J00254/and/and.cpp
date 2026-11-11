#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,t,sum,a[N],c[N][37],d[N],s[N][37];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int w=1,ans=a[i];
		while(ans){
			c[i][w]=ans%2;
			ans/=2;
			w++;
		}
		t=max(t,w);
	}
	for(int j=1;j<=n;j++) d[j]=1;
	for(int i=t;i>=1;i--){
		int ans=0,q[N],k=0;
		for(int j=1;j<=n;j++){
			if(d[j]) if(c[j][i]){
				q[++k]=j;
				ans++;
			}
		}
		sum*=2;
		if(ans<m) continue;
		for(int j=1;j<=n;j++) d[j]=0;
		for(int j=1;j<=ans;j++) d[q[j]]=1;
		sum+=1;
	}
	cout<<sum;
	return 0;
} 
