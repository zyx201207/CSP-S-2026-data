#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
long long island[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	int t;
	cin>>c>>t;
	while(t--){
		memset(island,0,sizeof(island));
		int n;
		int d;
		cin>>n>>d;
		for(int i = 0;i < n;i++){
			cin>>island[i];
		}
		long long cnt = 0;
		for(int i = 0;i < n - 3;i++){
			if(island[i + 3] - island[i] <= d){
				continue;
			}
			if(island[i + 1] - island[i] > d){
				continue;
			}
			if(island[i + 2] - island[i + 1] > d){
				continue;
			}
			if(island[i + 3] - island[i + 2] > d){
				continue;
			}
			if(island[i + 2] - island[i] > d && island[i + 3] - island[i + 1] > d){
				continue;
			}
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
