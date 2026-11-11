#include<bits/stdc++.h>
using namespace std;
int a[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,e,q;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){	
	}for(int j=0;i<=i;j++){
			if(a[i]==a[j]){
				e=i;
				for(int i=0;i<=e;i++){
					a[i]=0;
					++q;
				}
			}
		}
	cout<<q;
	
	
	return 0;
}