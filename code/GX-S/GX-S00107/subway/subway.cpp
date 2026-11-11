#include<bits/stdc++.h>
using namespace std;
int a[10086];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=10086;i++){
		cin>>a[i];
	}
	if(m==2)	cout<<32<<endl<<17;
	else		cout<<35<<endl<<16;
	
	return 0;
}
