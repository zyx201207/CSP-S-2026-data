//GZ-J00580 ·½å«Ïö 
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e6;
int a[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
