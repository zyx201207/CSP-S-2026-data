#include<bits/stdc++.h>
using namespace std;
int n;
long long a[300005];
char c[300005];
bool pd(char x,char y){
	return x<y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	sort(c+1,c+n+1);
	if(c[1]==c[n]){
		cout<<0;
		return 0;
	}
	return 0;
}
