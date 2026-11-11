#include <bits/stdc++.h>
using namespace std;

int c,t,n,d,x[2000001],dl[100001];

int main(){
	
	cin >> c >> t;
	for(int i=0;i<t;i++){
		cin >> n >> d;
		for(int j=1;j<=n;j++){
			cin >> x[j];
		}
		int f=0;
		for(int j=1;j<=n-1-d;j++){
			for(int y=j+1+d;y<=n;y++){
				if((x[y]-x[j])%d>0&&(y-j-1)>=2){
					f++;
				}
			}
		}
		dl[i]=f;
	} 
	for(int i=0;i<t;i++){
		cout << dl[i] << endl;
	}
	
	return 0;
}
