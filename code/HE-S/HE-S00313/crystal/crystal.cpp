#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	int n,ans=0;
	long long m;
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			cout <<4;
		}else{
			cout <<3;
		}
	}
	
	return 0;
}
