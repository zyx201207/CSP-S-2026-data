#include<bits/stdc++.h>
using namespace std;
int n,sum,t;
long long m,a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	t=1; 
	while(m>=0){
		if(a[t]==a[t+1]){
			t++;
			sum++;
		}else{
			m-=(a[t+1]-a[t])*t;
			sum++;
			t++;
		}
	}
	cout<<sum;
} 





