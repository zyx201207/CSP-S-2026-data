#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(m[i]>m[j]){
				cout<<m[i];
			}
			else cout<<m[j];
		}
	}

    return 0;
}
