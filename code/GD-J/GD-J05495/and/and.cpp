#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c[10086],d[10086];
	cin >> a >> b;
	for(int i=0;i<a;i++){
		cin >> c[i];
		d[i] = 0;
		int m = 1,j = c[i];
		while(j >= 1){
			int s = j-(j/2*2);
			d[i] += s*m;
			m = m*10;
			j = j/2;
		}
	}
	
	return 0;
}
