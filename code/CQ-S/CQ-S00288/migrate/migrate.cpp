#include <bits/stdc++.h>
using namespace std;
int T; 
int c,a[1005],ans,minn,n,d;
int f(int x,int y,int bs){
	if(x==y)
		return bs;
	int ans=1e9;
	for(int i=x+1;i<=y;i++)
		if(a[i]-a[x]<=d)
			ans=min(ans,f(i,y,bs+1));
	return ans;
}
int find(int x,int y,int bs){
	if(x==y){
		if(bs==minn)
			return 1;
		return 0;
	}
		
	int sum=0;
	for(int i=x+1;i<=y;i++)
		if(a[i]-a[x]<=d)
			sum+=find(i,y,bs);
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)	continue;
				minn=f(i,j,0);
				if(find(i,j,0)==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
