#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,ans=INT_MAX,e[31],cnt;
//10:10-10:30把T3写完了,T3好水
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		for(int j=0;j<=30;j++){
			e[j]+=(a[i]>>j)&1;
		}
	}
	int i=30;
	while(i--)if(e[i]>=m)break;
	for(int j=n;j>=1&&cnt<m;j--){
		if((a[j]>>i)&1)ans&=a[j],cnt++;	
	}
	cout<<ans;
	return 0;
}
