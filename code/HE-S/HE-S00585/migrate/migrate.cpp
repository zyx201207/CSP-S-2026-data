#include <bits/stdc++.h>
using namespace std;

int c,t;
int a[100001];
int y;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c,t;
	for(int i = 1;i<=t;i++){
        cin >>a[i];
	}
	for (int i = 1;i<=t;i++){
        for(int j = 1;j<=c;j++){
           y++;
        }
	}
	cout << y;
	return 0;
}
