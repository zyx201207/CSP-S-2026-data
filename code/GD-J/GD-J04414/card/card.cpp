#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define logn long
#define itn int
using namespace std;
long long n,m,a[500005],ans[300005];
int main(){
	fre("card");
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int b[500005],p=0;
		for(int j=0;j<505;j++)b[j]=0;
		for(int j=i;j<=n;j++){
			if(p==0){
				b[p++]=a[j];
			}
			else{
				for(int k=0;k<p;k++){
					if(b[k]==a[j]){
						p=k;
						break;
					}
				}
				b[p++]=a[j];
			}
		}
		for(int j=0;j<p;j++){
			ans[b[j]]++;
//			cout<<b[j]<<" ";
		}
//		cout<<endl;
	}
	for(itn i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
