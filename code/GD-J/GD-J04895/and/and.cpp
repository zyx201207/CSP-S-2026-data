#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[21000],s=0;
	for(int q=1;q<=n;q++){
		cin>>a[q];
	}
	sort(a+1,a+n+1);
	for(int w=1;w<=n-m+1;w++){
		int d=a[w];
	for(int q=w;q<=m;q++){
		d&=a[q];
	}
	if(d>s){
		s=d;
	}
}
cout<<s;
	return 0;
} 
