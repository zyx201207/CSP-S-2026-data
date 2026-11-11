#include<bits/stdc++.h>
using namespace std;
struct p{
	int num;
}a[300004];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if (m==2) cout<<n<<' '<<n;
	for (int i=0;i<n;i++){
		cin>>a[i].num;
		if (a[i].num!=a[i-1].num){
		    continue;
		}
	}
	
}
