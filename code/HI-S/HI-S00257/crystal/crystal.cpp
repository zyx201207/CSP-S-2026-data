#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
ll n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	
}
if(n<=6000){

sort(a+1,a+1+n);
for(int i=1;i<n;i++){
	b[i]=a[i+1]-a[i];
}

int ans=0;
for(int i=1;i<n;i++){
	int k=1;
	int sum=0;
	for(int j=i;sum<=m;j++){

	if(j>n) break;
		sum+=b[j]*k;
		k++;
	}
	
	ans=max(ans,k-1);
}

cout<<ans;
}else{
	long long sum=a[2]-a[1];
	int k=1;
	while(m>=0){
		m=m-sum*k;
		k++;
	}
	cout<<k-1;
}
	return 0;
}

