#include<bits/stdc++.h>

using namespace std;
long long n,m,a[1000000],c,b[1000000],t[1000000],s[1000000];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		c=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(t[c]!=a[j]){
					t[c]=0;
					c--;
				}
				c--;
			}
			b[a[j]]=1;
			c++;
		}
		for(int j=1;j<=m;j++){
			if(b[a[j]]==1){
				s[b[a[j]]]++;
				b[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << s[i] << " ";
	}
	return 0;
}