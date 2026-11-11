#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N];
bool b[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool g=0;
			int x=0;
			for(int w=i;w<=j;w++){
				if(a[j]==a[w]){
					g=0;
					x=w;
					break;
				}
			}
			if(g==0){
				
			}
		}
	}
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	return 0;
}
