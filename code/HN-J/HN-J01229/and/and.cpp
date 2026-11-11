#include<bits/stdc++.h> 
using namespace std;
int n,m,a[200015],Max_and;
int And(int x){
	if(x==n+1){
		return 0;
	}
	int anD;
	for(int i=x;i<=n;i++){
		anD=a[i]&a[i+1];
		Max_and=max(Max_and,anD);
		And(i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	And(1);
	cout<<Max_and;
	return 0;
}
