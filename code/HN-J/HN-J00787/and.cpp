#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m,c[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>c[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(c[j]<=c[j+1]){
					swap(c[j],c[j+1]);
				}
			}
		}
		cout<<c[1];
	}
	for(int i=1;i<=n;i++){
		
	}
	
	return 0;
} 
