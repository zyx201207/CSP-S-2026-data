//GZ-J00139 遵义市第十一中学 雷朝典 
#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","o",stdout);
	int n,m,b[20000];
	cin>>n>>m;
	for(int y=0;y<n;y++){
		cin>>b[y];
	}
	sort(b,b+n);
	cout<<b[n-m];
}
