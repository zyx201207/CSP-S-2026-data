#include<bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]==b[i-1]){
			cout<<0;
		}
	}
	
	return 0;
}
