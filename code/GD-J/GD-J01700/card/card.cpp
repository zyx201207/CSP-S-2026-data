#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
const int N=5e5+10;
int a[N];
int n,m,cnt=0,b=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b=((a[i]>=a[i-1])&b);
	}
	if(b){
		for(int i=1;i<=m;i++)cnt+=(a[i]<=i);
	}
	cout<<cnt;
	return 0;
}
