#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}	
	for(int i=30;i>=0;i--){
		int js=0;
		for(int j=1;j<=n;j++){
			if(b[j]==1){
				int t=(a[j]>>i)&1;
				if(t==1)	js++;
			}
		}
		if(js<m)	continue;
		ans+=(1<<i);
		for(int j=1;j<=n;j++){
			if(b[j]==1){
				int t=(a[j]>>i)&1;
				if(t!=1)	b[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
