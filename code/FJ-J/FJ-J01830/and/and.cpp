#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],cn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i+m-1<=n;i++){
		if(a[i]>cn)cn=a[i];
	}
	
	cout<<cn;
	return 0;
}
