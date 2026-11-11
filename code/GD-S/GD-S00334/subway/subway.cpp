#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q; 
int a[500010],a1[500010][4];
int t[500010];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >>a[i];
	}
	
	for(int i=1;i<=q;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a1[i][1] >> a1[i][2];
		}
	} 
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		t[1]=a[x]+a[y]+a1[1][1]+a1[2][1]+a1[2][2]+a1[3][2];
		t[2]=a[2]+a[3]+a1[2][2]+a1[2][3];
	}
	
	cout << t[1] << endl << t[2];
	
	return 0;
}
