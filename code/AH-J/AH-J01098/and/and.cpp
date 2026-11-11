#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,b[100005],maxn=-100000000,a;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>=maxn){
			maxn=a;
		}	
	}	
	cout<<maxn;
    return 0;
}
