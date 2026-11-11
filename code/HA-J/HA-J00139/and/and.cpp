#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],s=-1,d=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=s){
			d=s;
			s=a[i];
		}
	}
	if(m==1){
		
		cout<<s;
	}else if(m==2){
		cout<<d;
	}
			
	return 0;
}
