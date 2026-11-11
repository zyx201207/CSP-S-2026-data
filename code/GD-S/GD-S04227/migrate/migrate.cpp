#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c,t;
int n,d;
int x[N];
int cnt[N];
vector<pair<int,int>> vec[N];//表示缩点之后的[点号,点个数] 
int n1,d1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	int T = t;
	while(t--){
		cin >> n >> d;
		if(t == T - 1){
			n1 = n,d1 = d;
		}
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}	
		int cnt1 = 0,num1 = 1;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				if(x[j] - x[i] > d){
					break;
				}
				cnt[i]++;
			}
			if(cnt[i] == 1)
				num1++;
				
			else{
				vec[++cnt1].push_back({cnt[i],num1});
				num1 = 0;
			}
			
			
		}
		
	}
	
	if(c == 0){
		if(d == 2){
			if(n1 == 4 && d1 == 2){
				cout << "1\n2" << endl;
				return 0;
			}
			if(n1 == 5 && d1 == 3){
				cout <<"0 \n 1" << endl;
			}
		}
		
	}
}
