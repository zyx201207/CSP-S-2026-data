#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int a[500500],b[500500],c[500500],vis=1,d;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}for (int i = 1;i<=n;i++){
		d = i;
		for (int s= d;s<=n;s++){
			
			for (int j = 1;j<=vis;j++){
				
				if (c[j] == a[d]){
					vis  = 1;
					memset(c,0,sizeof(c));
					break;
				}
			}
			c[vis] = a[d];
			vis++;
			d++;	
		}
		
		for (int k = 1;k<=vis ;k++){
			b[c[k]]++;		
		}memset(c,0,sizeof(c));
		
	}for (int i = 1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
} 
