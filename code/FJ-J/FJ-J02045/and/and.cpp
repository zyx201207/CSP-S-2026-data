#include<bits/stdc++.h>
using namespace std;
int n,m,tnt=-100000;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(tnt<a[i-1]&a[i]){
			tnt=a[i-1]&a[i];
		}
	}
	cout<<tnt;
	return 0;
}
