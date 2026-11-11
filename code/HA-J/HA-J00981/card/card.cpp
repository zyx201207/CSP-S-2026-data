#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[700000],dq,cz[700000],ans[700000],cx[700000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	//xiang 3h zhi hui bao li eee
if(n*n<=200000000){
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=n;i>=1;i--){
		int dq=0;
		for(int r=i;r<=n;r++){
			if(cz[a[r]]){
				for(int e=cz[a[r]]+1;e<=dq;e++){
					cz[ans[e]]=0;
				}dq=cz[a[r]];
			}
			else {
				ans[++dq]=a[r];
				cz[a[r]]=dq;
			}
			
		}
		for(int i=1;i<=dq;i++){
			cz[ans[i]]=0;
			cx[ans[i]]++;
		}
	}for(int i=1;i<=m;i++)cout<<cx[i]<<" ";
}
else if(m<=2){
	long long sl1=0,sl2=0;
	for(int i=1;i<=n;i++){cin>>a[i];if(a[i]==1)sl1++;else sl2++;}
	if(a[n]==1)cout<<n<<" "<<sl2;
	else cout<<sl1<<" "<<n;
}
else{
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){
		ans[a[i]]=max(1LL*i,ans[a[i]]);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
	return 0;
}
