#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500005],ans=0,c[500005],k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//c[i]=c[i]+(a[i]-a[i-1])*(i-1);
	}
	sort(a,a+n);
	for(int i=2;i<=n;i++){
		//cout<<k<<endl;
		for(int j=i-ans-1;j>=1;j--){
			if(k<m){
				if(k+a[i]-a[j]<=m){
					ans++;
					k+=a[i]-a[j];
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		}
		k=k-(a[i-1]-a[i-1-ans])+(a[i]-a[i-ans]);
	}
	cout<<ans+1;
}
