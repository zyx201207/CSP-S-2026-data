#include</stdc++.h>
using namespace std;
long long ZL[1010],n,m;
int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ZL[i];
		m++;
		cout<<m;
	}
	return 0;
}
