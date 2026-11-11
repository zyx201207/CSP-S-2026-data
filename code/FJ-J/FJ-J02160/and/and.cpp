#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool b[200005];
int ans=0,n;
int op(int m,int x){
	if(x==n){
		return ans;
	}
	if(x==0){
		ans=a[0];
		for(int i=1;i<n;i++){
			b[i]=0;
		}
		b[0]=1;
		return op(n,x+1);
	}
//	for(int i=0;i<n;i++){
		if(b[x]==0){
			int h=(ans & a[x]);
			ans=max(h,ans);
			b[x]=1;
			x++;
			return op(n,x);
		}
//	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<op(m,0);
	return 0;
}
