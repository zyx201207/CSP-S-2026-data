//GZ-J00047 贵阳市第一中学 刘一萱 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const int M=3e5+5;
ll n,m,a[N],b[N],cnt[M],c[N];
ll f1,f2[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		f1=0;
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++){
			if (b[a[j]]==1){
				for (int k=j-1;k>=i;k--){
					b[f2[f1]]=0;
					f1--;
					
					if (f2[f1+1]==a[j]){
						b[a[j]]=1;
						break;
					}
				}
				f1++;
				f2[f1]=a[j];
			}
			else{
				b[a[j]]=1;
				f1++;
				f2[f1]=a[j];
			}
		}
		for (int j=1;j<=f1;j++){
			if (!c[f2[j]]){
				cnt[f2[j]]++;
			}
			c[f2[j]]=1;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
