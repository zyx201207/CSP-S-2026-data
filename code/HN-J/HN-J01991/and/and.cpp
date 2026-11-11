#include<bits/stdc++.h>
using namespace std;
bool p[200005][40],o[40];
void q(int a,int i){
	int j=0;
	while(a!=0){
		p[i][++j]=a&1;
		cout<<p[i][j];
		a>>=1;
	}
	cout<<"\n";
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m,i;	
	cin>>n>>m;
	for(i=1;i<=n;i++){
		int a;
		cin>>a;
		q(a,i);
	}
	return 0;
} 
