#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int t[114514],maxx=0;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x>maxx){
			maxx=x;
		}
	}
	cout<<maxx;
}
