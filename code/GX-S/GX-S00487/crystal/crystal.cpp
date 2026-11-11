#include<bits/stdc++.h>
using namespace std;
long long n,con=1,m,ans,anss=0;
long long a[500005];
int b[500005];
unsigned int c[23005][23004];
bool t=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&(a[i]-a[i-1])!=(a[2]-a[1]))t=0;
	}
	if(m==0){
		cout<<0;
		return 0;
	}
	if(t==1){
		ans=abs(a[2]-a[1]);
		for(int i=1;i<=n;i++){
			if((anss+(i*ans))>m||i==n){
				cout<<i;
				return 0;
			}
			else anss+=i*ans;
	}
}
	else{
	sort(a+con,a+n);
	for(int i=1;i<=n;i++){
		if(i>1){
			b[i-1]=abs(a[i]-a[i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			c[i][j]=b[j]+c[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		anss=i;
		ans=0;
		for(int j=1;j<=i;j++){
			ans+=c[j][i];
		}
		if(ans>m)break;
	}
	cout<<anss;
}
return 0;
}
