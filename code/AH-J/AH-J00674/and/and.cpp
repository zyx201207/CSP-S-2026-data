#include<bits\stdc++.h> 
using namespace std;
long long n,m,ex[10000005],h=0,b=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
    	cin>>ex[i];
	}
	for(long long i=1;i<=n;i++){
		h=ex[i]&ex[i+1];
		if(h>b){
			b=h;
	}
}
	cout<<b;
	return 0;
}
