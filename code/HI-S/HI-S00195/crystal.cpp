#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r", stdin);
	freopen("crystal.out","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long a[1005];
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	int num=0;
	for(int i=0;i<=m;i++){
		if(a[i]==a[i+1]){
			num++;
			continue;
		}
		a[i]=a[i]+1;
	}
	cout<<num;
	return 0;
}

