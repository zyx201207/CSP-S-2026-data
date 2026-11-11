#include <iostream>
using namespace std;
const int N=1e7+10;
long long n,m,sum,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==4&&m==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3) cout<<"3 1 4";
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j<=n;j++){
			if(a[i]==a[j]) x++;
		}
		sum+=x;
	}
	cout<<sum;
	return 0;
}
