#include <bits/stdc++.h>
using namespace std;
int dt[1000];
struct dtz{
	int time,bh;
}s[1000];
vector<vector<dtz> > arr (1000,vector<dtz>(1000));


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> dt[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin >> k;
		
		for (int i=1;i<=k;i++){
			cin >> s[i].bh >> s[i].time;
		}
		for (int i=1;i<k;i++){
			for (int j=i+1;j<=k;j++){
				arr[i].bh=s[].bh
			}
		}
	} 

	return 0;
}
