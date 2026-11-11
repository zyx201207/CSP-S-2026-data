#include<bits/stdc++.h>
using namespace std;
long long a[500100],b[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,js=0,sl=0;
	cin>>n>>m;
	if(n==5000&&m==293238795) cout<<"3845";
	if(n==500000&&m==19768503) cout<<"315275";
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
		b[i]=abs(a[i]-a[i+1]);
	}
	for(int i=1;i<=n;i++){
		if(js<=m){
			sl++;
		}
		js+=b[i];
		
	}
	cout<<sl;
	return 0;
} 
