#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=pow(2,30)-1,l=0;
    for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(d&a[j]>l){
		    	l=d&a[j];
		    	a[j]=0;
			}
		}
		d=l;
		l=0;
    }
	cout<<d;
	return 0;
}

