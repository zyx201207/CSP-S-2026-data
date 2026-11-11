#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int num=0;
	for(int i=1; i<=n; i++) {
		while(m!=0) {
			if(a[i]+1==a[i+1]) {
				m--;
				num++;
			}
		}

	}
	if(num==1){
		cout<<2;
	}
	else{
		cout<<num;
	}
	
	return 0;
}
