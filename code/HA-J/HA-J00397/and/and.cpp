#include <bits/stdc++.h>
using namespace std;
long long n,m,i,z;
string xx,yy;
int x,y;
int a[1000000100];




int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cout.tie(0);
	cin>>n>>m;
	for(i = 0;i<n;i++){
		cin>>a[i];
		while(a[i]>0){
			xx = xx+char(a[i]%2+'0');
		}

	}


	
	return 0;
}
