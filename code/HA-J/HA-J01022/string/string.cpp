#include<bits/stdc++.h>
using namespace std;
long long n,m,lon,ans;
string a,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>s;
		for(int j=0;j<m;j++){
			a=a+s;
		}
	}
	lon=a.size();
	for(int i=0;i<(lon+1)/2;i++){
		if(a[i]!=a[lon-i-1])ans++;
	}
	cout<<ans;
	return 0;
} 
