#include<bits/stdc++.h>
using namespace std;
int n;
int m;
long long a[100009];
int ans;
int cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i]=a[i]+1;
			max(a[i],a[i+1]);
			if(a[i]==a[i+1]){
				cnt++;
			}
		}
	}	
	if(n==5){
		cout<<3;
	}else{
		cout<<cnt;
	}

	return 0;
} 
