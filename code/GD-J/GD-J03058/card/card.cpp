#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
int a[500005];
int b[500005];                                   // b  模拟 
int ans[300005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin.tie();
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int ip=1;
	for(int i=1;i<=n;i++){                       // i 全部次数 
		memset(b,0,sizeof(b));
		ip=1;
		for(int j=i;j<=n;j++){                   // j 当前位置要放的卡 
			for(int k=1;k<=ip-1;k++){
				if(b[k]==a[j]){
					for(int l=k;l<=j;l++){
						b[l]=0;
					}
					ip=k;
					k=1e9;
				}
			}
			b[ip]=a[j];
			ip++;
		}
		for(int j=1;j<=n;j++){
			ans[b[j]]++;
		}
	//	cout << ans[1] <<' '<< ans[2] << ' ' << ans[3] << endl;
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
