#include<bits/stdc++.h>
using namespace std;
long long n,m,c,b;
long long a[1000005],s[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		for(int j=1;j<=b;j++){
			if(a[j]==c){
				for(int k=j;k<=b;k++){
					a[k]=0; 
					b--;
				}
				break;
			}
		}
		a[b]=c;
		b++;
		for(int q=1;q<=m;q++)
			for(int w=1;w<=b;w++)
				if(a[w]==q){
					s[w]++;
					break;
				}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
}
