#include<bits/stdc++.h>
using namespace std;
char a[2010],b[2010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(b[1]==b[0]){
			cout<<0;
			return 0;
		}
		cout<<min(a[0],a[1]);
		return 0;
	}
	
	return 0;
}