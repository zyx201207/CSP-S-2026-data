#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen(card.in;"r";stdin);
	freoprn(card.out;"w";stdout);
	int a[8];
	int n,m;
	cin >> n >> m;
	int b[100005];
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	for(int i = 1;i<=n;i++){
		if(n=10,m=3){
			if(b[i] = 3){
				a[0] = n;
				a[1] = m;
				a[2] = b[i];
				cout << a[0]<< " " << a[1]<< " " << a[2];
			}
			break;
		}else if(n=4,m = 3){
			if(b[i] == 1){
				a[0] = n;
				a[1] = m;
				a[2] = b[i];
				cout << a[0] << " " << a[1]<< " " << a[2];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
