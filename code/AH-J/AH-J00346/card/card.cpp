#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long n,m,cnt;
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt=max(cnt,a[i]);
	}
	cout<<n<<" "<<cnt<<" "<<m;
	return 0;
}

