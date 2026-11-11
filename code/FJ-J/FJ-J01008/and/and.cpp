#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],u[200005],ans=1,maxn=-1e9,num,sum=1,z;//num已选个数，sum a的数 
void fs(int x,int y){
	if(x!=0){
		u[x]=a[y];
	}
	if(m==x){
		for(int i=1;i<=x;i++){
			if(i==1){
				ans=u[i];
				continue;
			}
			ans&=u[i];
		}
		maxn=max(maxn,ans);
		ans=0;
		x-=1;
		return;
	}
	for(int i=1;i<=n-x;i++){
		if(i!=1){
			fs(x+y-1,y+x+i-1);
		}else{
			fs(x+1,y+x+i-1);
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1){
				z=a[i];
			}
			z&=a[i];
		}
		cout<<z;
		return 0;
	}
	fs(num,sum);
	cout<<maxn;
	return 0;
}
