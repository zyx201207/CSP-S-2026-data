#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long mxx=0,n,m,v[N],ans,a[N],mx,cnt;
map<int,string>mp;
map<int,int>mp1;
void dfs(long long aa,int bb){
	if(bb>=m){
		mxx=max(mxx,aa);
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(aa&a[i],bb+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			ans=a[1];
		}else{
			ans&=a[i];
		}
		mx=max(a[i],mx);
	}
	if(n==m){
		cout<<ans;
	}else if(m==1){
		cout<<mx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					long long aa=a[i];
					aa&=a[j];
					cnt=max(cnt,aa);
				}
			}
		}
		cout<<cnt;
	}else{
		for(int i=1;i<=n;i++){
			v[i]=1;
			dfs(a[i],1);
			v[i]=0;
		}
		cout<<mxx;
	}
	return 0;
}
// 5 3
//31 3 1 15 7
