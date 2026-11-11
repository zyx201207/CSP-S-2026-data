#include<bits/stdc++.h>
using namespace std;
int a[5010],m,n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>m>>n;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	cout<<m<<" "<<n<<" "<<a[1];
	return 0;
}

