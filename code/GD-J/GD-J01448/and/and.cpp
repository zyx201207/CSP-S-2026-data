#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n ,m a[10000],b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=b){
			b=a[i];
		}
	}
	cout<<b;
	return 0;
}
