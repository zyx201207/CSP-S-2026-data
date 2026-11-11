#include<bits\stdc++.h>
using namespace std;
long long n,m,ejz[100],ar[200010],ans;
bool v[200010];
void xs(int m,long long ans1){
	if(m<=0){
		ans=max(ans,ans1);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(ans1){
				xs(m-1,ar[i]&ans1);
			}else{
				xs(m-1,ar[i]);
			}
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	ejz[0]=1;
//	for(int i=1;ejz[i]<40000000000;i++){
//		ejz[i]=ejz[i-1]*=2;
//	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",ar+i);
	}
	xs(m,0);
	cout<<ans;
	return 0;
}
