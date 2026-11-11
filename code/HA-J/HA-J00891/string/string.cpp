#include<bits/stdc++.h>
using namespace std;
struct st{
	int s;
	string t;
}a[22222];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string as,as1;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin << a[i].s << a[i].t;
		as+=a[i].s*a[i].t;
	}
	for(int i=as.size;i>=1;i--){
		as1+=as[i-1];
	}
	if(as1 == as){
		cout << 0;
	}
	else{
		cout << 2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
