#include<bits/stdc++.h>
using namespace std;
long long a[200005],st[200005],b[200005],maxn=INT_MIN,n,m,c=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	else if(m==n){
		c=a[1];
		for(int i=2;i<=n;i++){
			c=c&a[i];
		}
		maxn=max(maxn,c);
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				c=a[i]&a[j];
				maxn=max(maxn,c);
			}
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					c=a[i]&a[j]&a[k];
					maxn=max(maxn,c);
				}
			}
		}
	}
	else{
		cout<<"0";
		return 0;
	}
	cout<<maxn;
	return 0;
}
