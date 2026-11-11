#include <bits/stdc++.h>
using namespace std;
long long n,c[200010][2],cnt,tnt,m,jishu1,jishu2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	cin >> n;
	for(int i=1;i<=n;i++){
		char b;
		cin >> c[i][0] >> b;
		c[i][1] = b - 'a' + 1;
		cnt += c[i][0];
	}
	m=n;
	if(cnt%2==1){
		while(m>1){
			if(c[jishu1+1][1] == c[n-jishu2][1]){
				if(c[jishu1+1][0] > c[n-jishu2][0]){
					c[jishu1+1][0] -= c[n-jishu2][0];
					jishu2 ++;
					m--;
				}else if(c[jishu1+1][0] < c[n-jishu2][0]){
					c[n-jishu2][0] -= c[jishu1+1][0];
					jishu1 ++;
					m--;
				}else if(c[jishu1+1][0] == c[n-jishu2][0]){
					jishu1 ++;
					jishu2++;
					m-=2;
				}
			}
			else if(c[jishu1+1][1] != c[n-jishu2][1]){
				if(c[jishu1+1][0] > c[n-jishu2][0]){
					tnt += c[n-jishu2][0];
					c[jishu1+1][0] -= c[n-jishu2][0];
					jishu2 ++;
					m--;
				}else if(c[jishu1+1][0] < c[n-jishu2][0]){
					tnt += c[jishu1+1][0];
					c[n-jishu2][0] -= c[jishu1+1][0];
					jishu1 ++;
					m--;
				}else if(c[jishu1+1][0] == c[n-jishu2][0]){
					tnt += c[jishu1+1][0];
					jishu1 ++;
					jishu2++;
					m-=2;
				}
			}
		}
	}else if(cnt%2==0){
		while(m>0){
			if(c[jishu1+1][1] == c[n-jishu2][1]){
				if(c[jishu1+1][0] > c[n-jishu2][0]){
					c[jishu1+1][0] -= c[n-jishu2][0];
					jishu2 ++;
					m--;
				}else if(c[jishu1+1][0] < c[n-jishu2][0]){
					c[n-jishu2][0] -= c[jishu1+1][0];
					jishu1 ++;
					m--;
				}else if(c[jishu1+1][0] == c[n-jishu2][0]){
					jishu1 ++;
					jishu2++;
					m-=2;
				}
			}
			else if(c[jishu1+1][1] != c[n-jishu2][1]){
				if(c[jishu1+1][0] > c[n-jishu2][0]){
					tnt += c[n-jishu2][0];
					c[jishu1+1][0] -= c[n-jishu2][0];
					jishu2 ++;
					m--;
				}else if(c[jishu1+1][0] < c[n-jishu2][0]){
					tnt += c[jishu1+1][0];
					c[n-jishu2][0] -= c[jishu1+1][0];
					jishu1 ++;
					m--;
				}else if(c[jishu1+1][0] == c[n-jishu2][0]){
					tnt += c[jishu1+1][0];
					jishu1 ++;
					jishu2++;
					m-=2;
				}
			}
		}
	}
	cout << tnt;
	return 0;
}
