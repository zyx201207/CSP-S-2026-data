#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mxx=-1,po,ans=-1,f[500005],num[500005];
char c;
//现在是星期六上午！
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		long long ssum=0;
		for(int j=1;j<=n;j++){
			long long r=0;
			for(int k=j;k<=n;k++){
				if(f[a[k]]!=0){
					r=f[a[k]];
				}else{
					r++;
					num[r]=a[k];
					f[a[k]]=r;
				}
			}
			for(int k=1;k<=r;k++){
				if(num[k]==i){ssum++; break;}
			}
			memset(f,0,sizeof(f));
		}
		cout<<ssum<<' ';
	}
	return 0;
}
