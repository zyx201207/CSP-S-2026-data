#include<bits/stdc++.h>
using namespace std;long long a[200005];bool e[200005];
long long sb(long long x,long long y){
	int w=0,s=1;
	while(x>0&&y>0){
		if((x&1)&&(y&1))w+=s;
		s*=2;x>>=1;y>>=1;
	}
	return w;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0;int x=0,y=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(sb(a[i],a[j])>ans){
				ans=sb(a[i],a[j]);x=i,y=j;
			}
		}
	}
	e[x]=1;e[y]=1;
	if(m==2){
		cout<<ans;return 0;
	}
	for(int i=3;i<=m;i++){
		long long an=0;int xx=0;
		for(int j=1;j<=n;j++){
			if(e[j])continue;
			if(sb(ans,a[j])>an){
				an=sb(ans,a[j]);xx=j;
			}
		}
		e[xx]=1;
		ans=an;
	}
	cout<<ans;return 0;
	
}
