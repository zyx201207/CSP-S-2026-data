#include<bits/stdc++.h>
using namespace std;
struct Node{
	bool ss;
	long long wz;
};
long long n,m,cnt ,x;
long long a[200010];
long long b[200010];
long long ans[200010];
Node c[200010];
bool p[300000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x=0;
		for(int i=1;i<=m;i++)c[i].ss=false;
		for(int i=1;i<=m;i++)p[i]=false;
		for(int j=i;j<=n;j++){
			if(!c[a[j]].ss){
				c[a[j]].ss=true;
				x++;
				c[a[j]].wz=x;
			}else{
				for(int o=c[a[j]].wz+1;o<=n;o++){
					c[a[o]].ss=false;
				}
				x=c[a[j]].wz;
			}
		}
		for(int j=1;j<=x;j++){
			if(!p[a[j]]){
				ans[a[j]]++;
				cout<<i<<" "<<a[j]<<endl;
				p[a[j]]=true;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	return 0; 
}
