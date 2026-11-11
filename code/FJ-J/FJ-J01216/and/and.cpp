#include <bits/stdc++.h>
using namespace std;

unsigned long long apt[200005];

int n,m;
unsigned long long arr[200005];
unsigned long long maxn = 0;

void func(int ceng,int hand){
	
	if(ceng==m+1){
		unsigned long long t = apt[1];
		for(int i=2;i<=m;i++){
			t = t&apt[i];
		}
		maxn = max(t,maxn);
		return;
	}
	
	
	for(int i=hand;i<=n-m+ceng;i++){
		apt[ceng] = arr[i];
		func(ceng+1,i+1);
	}
	
	return;
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	func(1,1);
	
	cout << maxn;
	
	return 0;
}
