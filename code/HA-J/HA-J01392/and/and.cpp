#include<bits/stdc++.h>
using namespace std;
int c[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]>ma){
			ma=c[i];
		}
	}
	if(m==1){
		cout<<ma;
	}
return 0;
}
