#include<iostream>
using namespace std;
int n,m,a[500005],cn[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cn[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(i==a[n])cout<<n<<" ";
		else cout<<cn[i]<<" ";
	}
	return 0;
}
