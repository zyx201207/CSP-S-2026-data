#include<bits/stdc++.h>
using namespace std;
int a[10005],c[10005];
int main(){
	//freopen("string.in","c",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i+1]){
			cout<<0;
			return 0;
		}
	}
}
