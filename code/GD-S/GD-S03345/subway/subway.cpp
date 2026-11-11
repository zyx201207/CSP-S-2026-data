#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[500050],k[510],a[510][500050],t[510][500050],x[100010],y[100010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ÊäÈë 
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	bool b = true;
	for(int i = 1;i <= n;i++){
		cin>>k[i];
		if(k[i] > 2){
			b = false;
		}
		for(int j = 1;j <= k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int begin_x,begin_y,end_x,end_y;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= k[i];j++){
				if(a[i][j] == x){
					begin_x = i;
					begin_y = j;
				}
				if(a[i][j] == y){
					end_x = i;
					end_y = j;
				}
			}
		}
		if(b){
			if(begin_y = 1){
				long long num = a[begin_x][0],sum = w[begin_x];
				while(begin_x != end_x and begin_y != end_y){
					for(int i = 1;i <= n;i++){
						for(int j = 1;j <= k[i];j++){
							if(a[i][j] == num and i != begin_x){
								sum = sum + t[i][j] + a[i][j];
							}
						}
					}
				}
				sum = sum + w[end_x];
				cout<<sum;
			}
		}
	}
	return 0;
}
