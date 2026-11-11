//special A
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool j=false;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		if(a[i]==0){
			cout<<0;
			return 0;
		}
	}
	cout<<a[m];
	return 0;
}
//Trick||Treat!
