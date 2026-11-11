#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(maxx<a[i]){
			maxx=a[i];
		}
	}
	if(m==1){
		cout<<maxx;
	}
	else{
		cout<<0;
	}
	return 0;
}
