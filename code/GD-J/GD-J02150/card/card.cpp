#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+1;
int n,m;
int a[maxn];
int num[maxn],top=1;//last 默认是上一个，next 下一个
int fi[3005],cnt[3005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int i0=0;i0<3005;i0++)fi[i0]=0;
		for(int j=i;j<=n;j++){
			if(fi[a[j]]==1){
				for(int w=top-1;w>=1;w--){
					if(num[w]!=a[j])top--,fi[num[w]]=0;
					else break;
				}
			}else num[top]=a[j],top++,fi[a[j]]=1;
		}
		for(int j=1;j<top;j++)cnt[num[j]]++;
		top=1;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
