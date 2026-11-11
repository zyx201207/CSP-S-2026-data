#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200010],f[200010],ans;
void cpp(int x,int y,int z){
	if(y==0){
		ans=max(ans,z);
		return;
	}
	int sum=0,id=0;
	for(int i=x+1;i<=n;i++){
		if(f[i])continue;
		if((a[i]&z)>sum){
			sum=(a[i]&z);
			id=i;
		}
	}
	f[id]=1;
	cpp(x,y-1,sum);
	f[id]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n==m)ans&=a[i];
		if(n==m&&i==1)ans=a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		cpp(i,m-1,a[i]);
		f[i]=0;
	}
	cout<<ans;
	return 0;
}
