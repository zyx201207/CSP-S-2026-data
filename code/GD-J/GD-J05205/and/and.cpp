#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,q[20009],a,b=0;
	cin>>n>>m;
	if(m==1){
		for(int i=0;i<n;i++){
			cin>>a;
			b=max(a,b);
		}
		cout<<b;
	}
}
