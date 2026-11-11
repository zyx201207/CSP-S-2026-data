#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,a[100003],m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int b=a[1];
	for(int i=1;i<=m;i++){
		b=(b&a[i]);
	}
	cout<<b;
}
