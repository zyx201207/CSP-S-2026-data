#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,f[N],ans;
long long a[N],m,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,less<int>());
	for(int k=1;k<=n;k++){
		for(int p=1;p<=m;p++) f[p]=0;	
		for(int i=1;i<=k;i++){
		s=a[k]-a[i];
			for(int j=m;j>=1;j--){
				if(j>=s){
					f[j]=max(f[j],f[j-s]+1);		
				}
			}
			//for(int p=1;p<=m;p++) cout<<f[p]<<' ';
			//cout<<endl;
		}
		//cout<<endl;
		ans=max(ans,f[m]);
	}
	cout<<ans;
	return 0;
}
