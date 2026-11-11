#include<bits/stdc++.h>
using namespace std;
int n,m,z[200005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>z[i];
	sort(z,z+n,cmp);
	cout<<z[m-1];
	return 0;
}
