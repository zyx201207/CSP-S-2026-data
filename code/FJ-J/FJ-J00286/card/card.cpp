#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,b;
	int jiji=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			if(a[i]==a[j]){
				for(int k;k<=i-1;k++){
					a[k]=0;
				}
				jiji=i;
			}
		}
		
	}
	for(int i=jiji;i<=n;i++){
		cout<<i;
	}
	return 0;
}
