#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000010],b[10000000],c[10000000];
long long ret=0;
long long num=0;
int main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
	} 
	for(int i=1;i<=n;i++){	
		if(a[i]+1==a[i+1]){
			ret++;
		}		
		else{
			while(a[i]==a[i+1]){
				a[i]++;
				ret++;
			}
		}
		b[i]=ret;
		if(b[i]>m){
			b[i]=0;
		}
		else if(b[i]<=m){
			if(b[i]<b[i+1]){
				c[i]=b[i];
			}
		}
		if(b[i]){
			num++;
		}
}
		cout<<num-2;	
				return 0;
	} 
