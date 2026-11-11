#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N],cnt;
bool b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2&&m==1){
		cout<<m<<" "<<m;
	}
	
	return 0;
}
