#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if((a[i]&a[i+1])>s){
			s=a[i]&a[i+1];
		}
	}
	cout<<s;
	return 0;
}
