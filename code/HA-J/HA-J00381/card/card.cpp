#include<bits/stdc++.h>
using namespace std;
long long c[300009],a[500009],t[500009];
string a1="";
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]=0;
	}int l=0;
	for(int i=1;i<=n;i++){
		a1="";
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				a1+=(a[j]+'0');
				c[a[j]]+=1;
			}else{
				a1="";
				a1+=(a[j]+'0');
			}
		}
		for(int z=0;z<=a1.size();z++){
			for(int v=1;v<=m;v++){
				if(v==a1[z]-'0'){
					t[v]+=1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			c[a[j]]=0;
		}		
	}
	for(int i=1;i<=m;i++){
		if(t[i]!=0){
			cout<<t[i]<<" ";
		}
	}
	return 0;
} 
