//GZ-J00276 »ÆÈË÷ë 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		}
		return cout<<ans,0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(a[i],ans);
		return cout<<ans,0;
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n;i>=m;i--) ans&=a[i];
	cout<<ans;
	return 0;
}
