#include<bits/stdc++.h>
using namespace std;
int n,m,a[600006],s=pow(2,31)-1;
int max(){
	int l=a[1];
	for (int ll=1;ll<=n;++ll){
		if (a[ll]>l)l=a[ll],s&=a[ll];
	}
	return l;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n;cin >>m;
	for (int i=1;i<=n;++i)cin>>a[i];
	if(m=1){cout <<max();}else{cout <<s;}
	return 0;
} 
