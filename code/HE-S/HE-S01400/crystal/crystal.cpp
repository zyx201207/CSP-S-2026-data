#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(crystal.in,"r",stdin);
	freopen(crystal.out,"w",stdout);
	int n,m,b,x;
	string a;
	cin>>n>>m>>a>>x;
	for(int i=1;i<=n;i++){
		b=a[i]/n;
		if(a[i]!=b){
			a[i]+=1;
			x++;
			m-1;
		}
	}
	cout<<x+1;
	return 0;
}
