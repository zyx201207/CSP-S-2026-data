#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    int n,m;
    int cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		int k;
		cin>>k;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(k[i]=k[j){
				cnt++;
			}
			else{
				break;
			}
		}
	}
	cout<<cnt;
    return 0;
}
