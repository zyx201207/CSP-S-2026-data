#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005];
string b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b.find(a[j])!=-1){
				b.erase(b.find(a[j]),b.size()-1);
			}
			b+=a[j]+'0';
		}
		for(int j=1;j<=n;j++){
			if(b.find(j+'0')!=-1){
				int x=b[i]-'0';
				c[x]=i;
			}
		}
		
	} 
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
} 
