#include<iostream>
#include<string>
using namespace std;

int a[500050],c[500050];

int b[500050];

		int d[500050];
int main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int j = 1; j <= n; j++){
		int zhan[500050],top=0;
		for(int i = j; i <= n; i++){
			zhan[++top] = a[i];
			if(d[a[i]]){
				while(1){
					top--;
					if(zhan[top] == a[i]){
						break;
					}
				}
			}
			d[a[i]]++;
		}
		for(int i = 1;i <= top;i++){
			//cout << zhan[i] << ' ';
			c[zhan[i]]++;
		}
		//cout << top;
		//cout << '\n';
	}
	for(int i = 1; i <= m; i++){
		cout << c[i] << ' ';
	}
	return 0;
}
