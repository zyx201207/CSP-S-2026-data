#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	cin>>n>>m;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	cout<<ma;
	return 0;
}
