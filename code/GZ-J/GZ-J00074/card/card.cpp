//×¼¿¼Ö¤ºÅ£ºGZ-J00074 ÐÕÃû£ººú¾þºÀ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<int>st;
const int N=5e5;
const int M=3e5;
int n,m,a[N],b[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=m;i>=1;i--){
		cout<<i<<' ';
	}
	return 0;
}
