#include <bits/stdc++.h>
using namespace std;
bool flg=0;
int a[100005],b[100005],c[100005],cnt=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[1]=a[i];
		cnt=1;
		for(int j=i;j<=n;j++){
			flg=0;
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]){
					flg=true;
					for(int p=k;p<=n;p++){
						b[p]=0;
					}
					cnt=k;
					b[cnt]=a[j];
					break;
				}
			}
			if(flg=false){
				cnt++;
				b[cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			c[b[j]]++;
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
// 湖南省株洲市第二中学
// Luogu 1226884 1251088
//  No.2 Middle School of Zhuzhou Hunan
// 0pts 尽力了
 
