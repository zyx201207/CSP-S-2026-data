//GZ-S00265 观山湖中学 吴昆灿
#include<bits/stdc++.h>
using namespace std;
int n[100000],u,v,x[1000][1000],c,t,d[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=0;i<t;i++){
		int min=100000000;
		cin >> n[i] >> d[i];
		for(int j=0;j<n[i];j++){
			cin >> x[j][i];
		}	
	}
	for(int i=0;i<t;i++){
		int num=0;
		for(int j=0;j<n[i];j++){
			int numx=0;
			for(int k=d[i];k>0;k--){
				if(x[j][i]+k == x[i][i]){
					numx++;
				}
			}
			if(numx > num){
				num=numx;
			}
		}
		cout << num << endl;
	}
	return 0;
}
