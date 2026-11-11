#include <bits/stdc++.h>
using namespace std;
char c[20000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int cnt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		char k;
		cin>>k;
		for(int j=1;j<=t;j++){
			c[cnt+j]=k;
		}
		cnt+=t;
	}
	int l=1;
	int r=cnt;
	int ans=0;
	while(l<=r){
		if(l==r){
			break;
		}
		if(c[l]!=c[r]){
			ans++;
		}
		l++,r--;
	}
	cout<<ans<<endl;
	return 0;
}
// 湖南省株洲市第二中学
// Luogu 1226884 1251088
//  No.2 Middle School of Zhuzhou Hunan
// 56pts?
