#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2*100000+10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	int y=a[n];
	for(int i=n-2;i>=m;i--) y=(y&a[i]);
	cout<<y;
	return 0;
}

