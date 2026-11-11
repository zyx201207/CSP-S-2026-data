#include<bits\stdc++.h> 
using namespace std;
long long n,m,ex[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ex[i];
	}
	cout<<n<<" "<<m<<" "<<ex[1];
   
	return 0;
}
