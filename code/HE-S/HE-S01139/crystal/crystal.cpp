#include<bits/stdc++.h>
using namespace std;
const int N=1e12+10; 
typedef long long LL;
string a;
LL n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans,maxx;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		if(a[i]!=a[i+1]&&m>=(a[i+1]-a[i])*(i+1)){
			m-=(a[i+1]-a[i])*(i+1);
			for(int j=0;j<=i;j++){
				a[j]=a[i+1];
			}
		}
	}
	for(int i=0;i<n;i++){
		ans=1;
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				ans++;
			}
		}
		maxx=max(ans,maxx);
	}
	cout<<maxx;
	return 0;
} 
