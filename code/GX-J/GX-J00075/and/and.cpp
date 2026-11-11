#include <bits/stdc++.h>
using namespace std;
bool ps(int a,int b){return a>b;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,ps);
	int s=a[0];
	for(int i=1;i<m;i++){s=s&a[i];}
	cout<<s;
	return 0;
}
