#include<bits/stdc++.h> 
using namespace std;
long long a[500005],b[500005];long long n,m,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	
	}
sort(a,a+n);

for( int j=n-2;;){
	if(m<=0){
		break;
	}

	if((a[n-1]-a[j]<=m)&&j>=0){
		m=m-(a[n-1]-a[j]);
		ans++;j--;
	}else {
		break;
	}
	}
	

	cout<<ans;
	return 0;
}
