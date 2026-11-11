#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int da;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((a[i]&a[j+1])>(a[i]&a[j+2])){
				da=a[i]&a[j+1];
			}
		}
	}
	cout<<da;
	return 0;
}

