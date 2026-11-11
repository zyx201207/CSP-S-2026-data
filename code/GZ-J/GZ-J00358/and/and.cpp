//GZ-J00358 ³ÂŞÈÃù  
#include <bits/stdc++.h>
using namespace std;
int andd(int m,int n,int a[10005]){
	int l;
	if(m>0){
		for(int i=0;i<m;i++){
			l=a[i]&andd(m,n,a);
		}
	}
	return l;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<andd(m,n,a);
	return 0;
}
