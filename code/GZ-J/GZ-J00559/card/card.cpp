//GZ-J00559 遵义市第十二中学 李承昊 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,ans[300005],a[N],last[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int len=0;
		for(int j=1;j<=n;j++) last[j]=0;
		for(int j=i;j<=n;j++){
			len++;
			if(last[a[j]]==0) last[a[j]]=len;
			else{
				for(int k=1;k<=m;k++) if(last[k]>=last[a[j]]) last[k]=0;
				last[a[j]]=len;
			}
		}
		for(int j=1;j<=m;j++)
			if(last[j]!=0) ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
