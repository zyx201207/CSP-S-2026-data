#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int ret,cnt;
int a[1000010][1000010];
int x[1000010];
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	while(c--){
		cin>>n>>m>>d>>q;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin>>a[i][j];
				ret+=a[i][j];
			}
		}
		cin>>d;
		cin>>q;
		for(int r = 0;r < q;r++){
			cin>>x[r];
		}
		
		for(int i = 0;i < q;i++){
			cout<<ret;
		}
		ret=0;
	}
	fclose(stdin);
	fclose(stdout);
}
