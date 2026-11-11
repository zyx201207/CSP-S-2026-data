#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2005];
string x,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=0;
	if(n==1){
		for(int i=1;i<=n;i++){
			if(maxx<a[i]){
				maxx=a[i];
			}
		}
	}
	cout<<maxx;
	return 0;
}
