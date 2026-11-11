//GZ-J00350 贵阳市第三实验中学 郑思成
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f
#define INF 0x3f3f3f3f3f3f
using namespace std;
int n, m;
int a[500010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n>> m;
	for(int i=1;i<=n;i++){
		cin >> a[i]; 
	}
	for(int i=1;i<=n;i++){
		int d[500010];
		int tong[300010];
		int cnt=0;
		for(int j=1;j<=n+1;j++){
			d[i]=0;
		}
		for(int j=1;j<=m+1;j++){
			tong[j]=0;
		}
		for(int j=i;j<=n;j++){
			tong[a[j]]++;
			if(tong[a[j]]==2){
				int f;
				for(int k=1;k<=n;k++){
					if(d[k]==a[j]){
						f=k;
						break;
					}
				}
				for(int k=f;k<=cnt;k++){
					d[k]=0;
				}
				cnt=f;
			}else{
				cnt++;
				d[cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			tong[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}

