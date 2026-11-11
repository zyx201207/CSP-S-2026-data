#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin >> a;
	int x[a];
	char y[a],y1[2000000];
	memset(y1,0,sizeof(y1));
	for(int i = 0;i < a;i++){
		cin >> x[i] >> y[i];
	}
	long long p = 0;
	for(int i = 0;i < a;i++){
		for(int j = p;j < x[i]+p;j++){
			y1[j] = y[i];
		}
		p+=x[i];
	}
	long long cnt = 0,all = 0;
	for(int i = 0;i < a;i++){
		all+=x[i];
	}
	all/=2;
	long long ans = 0;
	for(int i = 0;i < all;i++){
		if(y1[i] != y1[p-i-1]){
			ans++;
		}
	}
	cout << ans;
}
