#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,sum=0;
	cin >> n >> a;
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	for(int i=0;i<=n;i++){
		if(n+a==0){
			sum++;
		}
	}
	cout << sum << endl; 
	return 0;
}
