#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxx=0;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		sort(a+1,a+n+1);
		cout<<a[n-2]&&a[n-1];
	}
	
	if(m==1){
		cout<<a[n];
		return 0;
	}
	return 0;
}

