#include<bits/stdc++.h>
using namespace std;
long long a[200010],ans=-1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==2&&n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0; 
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
