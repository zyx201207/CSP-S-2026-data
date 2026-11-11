#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    for(int i=m;i>=1;i--){
		cout<<i<<" ";
	}
    return 0;
}
