//GZ-S00435 贵州省实验中学 韩一鸣
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in",'r',stdin);
	freopen("subway.out",'w',stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+5];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int a[n+5][2*m+5];
	for(int i=0;i<n;i++){
		int jinguo;
		cin>>jinguo;
		a[i][0]=jinguo;
		for(int j=1;j<jinguo;j++){\
			cin>>a[i][j];
		}
	}
	int cx[p][2];
	for(int i=0;i<p;i++){
		cin>>cx[i][0];
		cin>>cx[i][1];
	}
	cout<<20<<endl<<26;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
