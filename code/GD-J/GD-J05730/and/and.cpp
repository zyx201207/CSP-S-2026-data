#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6;
int a[N],n,m,c=-78;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	} else if(m==2){
		int ans=0x3f3f3f3f;
		ans*=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i] and a[j] >ans) ans=a[i] and a[j];
			}
		}
		cout<<ans;
	} else if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans and a[i];
		}
		cout<<ans;
	}
	return 0;
}
