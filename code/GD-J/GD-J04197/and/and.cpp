#include <iostream>
#include <algorithm>
using namespace std;
bool no[200005];
int a[200005],m,n;
int ans=(1<<30)-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=30;j>=1;j--){
		int can=0;
		for(int i=1;i<=n;i++)if(!no[i]&&(a[i]>>(j-1))&1)can++;
		if(can<m)continue;
		for(int i=1;i<=n;i++)if(!((a[i]>>(j-1))&1))no[i]=1;
	}
	for(int i=1;i<=n;i++)if(!no[i])ans&=a[i];
	cout<<ans;
}
