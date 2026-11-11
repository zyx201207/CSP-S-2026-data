#include<bits/stdc++.h>
using namespace std;
int n;
struct d{
	int a;
	char c;
}b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
	}
	if(n<=1){
		cout<<"0";
		return 0;
	}
	return 0;
}
