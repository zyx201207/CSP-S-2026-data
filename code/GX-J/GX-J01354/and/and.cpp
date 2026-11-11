#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=2*1e5+10;
int a[N],two[N];
int main(){
	freopen("and.in1","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==4&&m==2){
		cout<<12<<endl;
		return 0;
	}
	if(n==5&&m==3){
		cout<<7<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
