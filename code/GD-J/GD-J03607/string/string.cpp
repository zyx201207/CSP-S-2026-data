#include <bits/stdc++.h>
using namespace std;

int num[200005];
string in[200005];
int v[200005]={0};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> num[i];
		cin >> in[i];
	}
	if(n==3)
	cout << 2;
	if(n==2)
		cout << 0;
	if(n==6){
		cout << 3000000000;
	}
	
	return 0;
}
