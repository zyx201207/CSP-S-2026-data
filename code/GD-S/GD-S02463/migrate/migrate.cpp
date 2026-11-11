#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define filename "migrate" 

int n,c,t,d;
int a[2000006],b[2000006];
struct sss{
	int len,num;
}ss1[5005][5005],ss2[5005][5005];

//void pri(){
//		for(int i = 1;i<=n;i++){//枚举起点 
//			for(int j = 1;j<=n;j++){//枚举终点 
//				cout <<ss[i][j].num <<' ';
//			}cout << endl;
//		}cout << endl;
//}

signed main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	cin >>c>>t;
	for(int k = 1;k<=t;k++){
		int ans = 0;
		cin >> n>>d;
		if(n>5000){
			int x1,x2,as;
			for(int i = 1;i<=n-2;i++){
				cin >> x1;
			}			
			cin >> x1>>x2;
			as = x2-x1;
			if(x2-x1>d){
				cout << 2<<endl;
			}
			else cout << 0<<endl;
			
			
		}

		for(int i = 1;i<=n+1;i++){
			for(int j = i;j<=n+1;j++){
				ss1[i][j].num = 0;
				ss1[i][j].len = 0;
			}
		}
		
		for(int i = 1;i<=n;i++){//枚举起点 
			for(int j = i+1;j<=n;j++){//枚举终点 
//				ss[i][j] = a[j]-a[i];
				if(a[j]-a[i]<=d){
					ss1[i][j].num++;
//					ss2[i][j].num = ss1[i][j].num
					ss1[i][j].len = 1;
				}
			}
		}		
		
		for(int i = 1;i<=n;i++){//枚举起点 
			for(int j = n;j>1;j--){//枚举终点 
				ss1[1][i].num+=ss1[j][i].num;
			}
		}
		
		for(int i = 1;i<=n;i++){//枚举起点 
			for(int j = 1;j<=n;j++){//枚举终点 
				if(ss1[i][j].len == 0&&ss1[i][j].num == 2){
					ans++;
				}
			}
		}
		cout <<ans<<endl;
	}
	
	return 0;
}
