#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr);
	int n,sum=0,cnt=0;
	cin>>n;
	int m;
	cin>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==1)continue;
		else{
			if(a[i-1]+1==a[i]){
				cnt++;
				sum++;
		}
		}
		if(sum==m)break;
	}
	cout<<cnt;
	return 0;
} 
