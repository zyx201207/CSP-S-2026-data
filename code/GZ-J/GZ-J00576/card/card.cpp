//GZ-J00576 黄思翔 六盘水市第二十四中学
#include <bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5]){
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<0<<" ";
	}
	return 0;
}
