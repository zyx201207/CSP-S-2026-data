#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0,c;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c;
		if(c>=max)
			max=c;
	}
	cout<<max;
	return 0;
}
