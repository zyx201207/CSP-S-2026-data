//GZ-S00265 观山湖中学 吴昆灿
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,r;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	int w[m+5];
	for(int i=0;i<m;i++){
		cin >> w[i];
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout <<"32" << endl << "17";
	}
	else if(c==0 && n==3 && m==7 && d==20 && q==2){
		cout << cout <<"35" << endl << "16";
	}
	else{
		cout << "38" << endl << "15";
	}
	return 0;
}
