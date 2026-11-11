#include<bits/stdc++.h>
using namespace std;
const int A=2e5+5;
int n,m;
int a[A];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	int b[A];
	for(int i=30;i>=0;i--){
		sort(a+1,a+1+n);
		int z=lower_bound(a+1,a+1+n,(1<<i))-a;
		//cout<<n-z+1<<" "<<i<<"\n";
		if(n-z+1>=m){
			ans+=(1<<i);
			for(int j=z;j<=n;j++)b[j-z+1]=a[j]-(1<<i);
			n=n-z+1;
			//cout<<":"<<n<<'\n';
			for(int j=1;j<=n;j++){
				a[j]=b[j];
				//cout<<a[j]<<" ";
			}
		}else for(int j=z;j<=n;j++)a[j]-=(1<<i);
		
	}
	cout<<ans;
	return 0;
}
