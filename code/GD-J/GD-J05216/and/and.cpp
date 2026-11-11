#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],n,m,ans;
bool f[N];
void p(int c,int sum){
	if(c>m){
		ans=max(ans,sum);
		return;
	}
	for(int i=c;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			if(c==1){
				p(c+1,a[i]);
			}else{
				p(c+1,sum&a[i]);
			}
		}
		f[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	p(1,0);
	cout<<ans;
	return 0;
}
