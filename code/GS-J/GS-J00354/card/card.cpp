#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i= 0;i<n;i++){
		cin >> a[i];
	}
	if(n==1){
		cout << "1 1 1";
	}
	return 0;
}
