#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],tong[N];
int n,m;
void solve1(){
	for(int i=1;i<=n;i++){
		tong[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<=2){
		solve1();
	}
	return 0;
}
