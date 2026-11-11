#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,a[1000000],s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	sort(a,a+n,cmp);
	s=a[0];
	for(int i=1;i<m;i++){
		s&=a[i];
	}
	cout<<s;
}
