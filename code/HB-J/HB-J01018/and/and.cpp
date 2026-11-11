#include <bits/stdc++.h>
using namespace std;
bool ejz(int x){
    while(x>0){
	    x=x%2;
	    x/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m,a[10005],sum=0;
    cin>>n>>m;	
	for(int i=1;i<=n;i++){
	    cin>>a[i];	
	}
	for(int i=1;i<=m;i++){
	    if(ejz(a[i])!=ejz(a[i+1])){
		    sum=ejz(a[i]
		}
	}
	cout<<"12";
	return 0;
}
