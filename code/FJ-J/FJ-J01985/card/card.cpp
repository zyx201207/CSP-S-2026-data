#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+40;
int n,m,tail;
int ans[N],a[N],b[N];
bool chk(int pnt){
	for(int i=1;i<=tail;i++)
		if(b[i]==pnt)return 0;
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		tail=0;
		for(int j=i;j<=n;j++){
			if(chk(a[j]))
				b[++tail]=a[j];
			else{
				while(tail){
					if(b[tail]==a[j]){
						b[tail]=0;break;
					}
					b[tail]=0;
					tail--;
				}
				b[tail]=a[j];
			}
		}
		for(int k=1;k<=tail;k++)
			ans[b[k]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
