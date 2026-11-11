#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string a,b;
	for(int i=1;i<=18;i++){
		for(int j=1;j<=5;j++){
			int che[101]={i,j};
			if(che[c1]=che[c2]){
				a = '1';
				b=a;
				
			}else{
				a += '0';
				b=a;
			}
			
		}
	}
	cout << b;
	return 0;
}

