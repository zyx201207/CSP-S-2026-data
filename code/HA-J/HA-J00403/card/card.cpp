#include<bits/stdc++.h>
using namespace std;
int n,m,p,q;
int a[100010],b[100010],c[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	if(m<=2){
		p*=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]!=a[1]){
				q*=a[i];
				break;
			} 
		}
		for(int i=1;i<=n;i++){
			b[a[i]]++;
			if(b[a[i]]>1){
				for(int j=p;j<a[i];j++){
					a[j]=0; 
				}
				for(int k=a[i];k<=n;k++){
					b[k]++;
				}
				b[a[i]]=1;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
