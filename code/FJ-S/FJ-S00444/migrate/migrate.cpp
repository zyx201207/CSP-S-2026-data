#include<bits/stdc++.h>
using namespace std;
long long a[2000005],b[1000005];
vector<int>c[2000005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]+b[i-1];
		}
	}
}
