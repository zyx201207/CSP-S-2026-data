#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
using namespace std;
int n,m,a[N],b[N],book[N],cnt;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		cnt=0;
		for(int j=i;j<=n;j++){
			int fl=0;
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]){
					fl=1;
					for(int l=k+1;l<=cnt;l++)b[l]=0;
					cnt=k;
					break;
				}
			}if(fl==0)b[++cnt]=a[j];
		}for(int j=1;j<=cnt;j++){
			book[b[j]]++;
		}
	}for(int i=1;i<=m;i++)cout<<book[i]<<' ';
	return 0;
}	
