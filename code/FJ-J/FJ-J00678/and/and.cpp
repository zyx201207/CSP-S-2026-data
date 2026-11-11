#include<bits/stdc++.h>
using namespace std;
long long a[200005],f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	long long x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((a[i]&a[j])>f[2]&&i!=j){
				f[2]=(a[i]&a[j]);
				x=i;
				y=j;
			}
			
		}
	} 
	for(int i=1;i<=n;i++){
		if(i==x||i==y)continue;
		for(int j=m;j>2;j--){
			f[j]=max(f[j],(f[j-1]&a[i]));
		} 
			
	}
	cout<<f[m];
	return 0;
}
