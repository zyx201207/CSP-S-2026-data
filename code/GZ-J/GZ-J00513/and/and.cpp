//GZ-J00513 兴义市弘毅中学 李宇轩 
#include<bits/stdc++.h>
using namespace std;
long long a,b,y[10000000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	
	for(int x=1;x<=a;x++){
		cin>>y[x];
	}
	sort(y+1,y+a+1);
	cout<<y[a-b+1];
	
	
	return 0;
}
