#include<bits/stdc++.h>
using namespace std;
long long a[500005],q[500005],m;
int ans,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q[0]=0;
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}for(int i=2,j=1;i<=n;){
		if(a[i]*(i-j+1)-(q[i]-q[j-1])<=m){
			ans=max(ans,i-j+1);
			i++;
		}
		else{
			j++;
		}
	}
	cout<<ans;
	return 0;
}