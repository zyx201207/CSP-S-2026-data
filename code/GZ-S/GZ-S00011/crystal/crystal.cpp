//GZ-S00011 贵阳市南明区李端棻中学 郑传韬 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;;i++){
		if(m<(a[i+1]-a[i])*i){
				break;
			}
		for(int j=i;j>=1;j--){
			m-=a[j+1]-a[j];
			a[j]=a[j+1];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
