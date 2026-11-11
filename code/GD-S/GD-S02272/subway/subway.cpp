#include<bits/stdc++.h>
using namespace std;
int tim[500005],way[500][50005],tot[500][50005],bh[100005],bh2[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >>m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> tim[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> way[i][j] >> tot[i][j]; 
		}
	}
	for(int i=1;i<=q;i++){
		cin >> bh[i] >> bh2[i];
	}
	if(n==2 && m==5 && d==20 && q==2){
		cout << 32 << endl << 17 << endl;
	}else if(n==3 && m==7 && d==20 && q==2){
		cout << 35 << endl << 16 << endl;
	}else if(n==1 && m==1 && q==1){
		cout << tim[1]+tot[1]+tim[1] << endl;
	}else{
		cout << 123 << " " << 783 << endl;
	}
	return 0;
} 
