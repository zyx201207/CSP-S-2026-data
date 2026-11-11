#include<bits/stdc++.h>
using namespace std;
long long a[1000007];
long long n,m,ans,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--){
			for(int k=1;k<=m-1;k++){
				ans=a[i]&a[j];
				c=max(ans&c,c);
			}
			
		}
	}
		
	cout<<ans<<endl;
	return 0;
}
