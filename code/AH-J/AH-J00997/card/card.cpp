#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,minn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		minn=max(a,minn);
	}
    cout<<n<<minn<<m;
	return 0;
} 
