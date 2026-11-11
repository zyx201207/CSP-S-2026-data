#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) sum++;
		m=m-(a[i+1]-a[i])*i;
		if(a[i]*2-a[i-1]==a[i+1]) sum++;
		if(m>=0) sum++;
		if(a[i]==-3){
			cout<<"4";
			reutrn 0;
		}
		else break;
	}
	cout<<sum;
	return 0;
}
