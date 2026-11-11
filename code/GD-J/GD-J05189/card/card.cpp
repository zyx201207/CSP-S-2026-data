#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[510000];
	int b[510000];
 	int t1[510000];
	bool f=true;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			f=false;
		} 
	}
	if(m==1){
		cout<<n;
	}
	else if(f){
		int t[500003];

		for(int i=1;i<=m;i++){
			t[i]=-1;
		}
		for(int i=1;i<=n;i++){
			t[a[i]]=max(t[a[i]],i);

		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
		
		
	}
	else{
		int c[510000][5];
		int a1[510000];
		for(int i=1;i<=n;i++){
			a1[i]=a[i];
		
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(c[a1[j]][1]==1){
					for(int k=c[a1[j]][2];k<=j;k++){
						a1[i]=-1;
						c[a1[k]][1]=0;
					}
					
				}
				else{
					c[a1[j]][1]=1;
					c[a1[j]][2]=j;
				}
			}
			for(int j=1;j<=m;j++){
				if(c[j][1]!=-1){          
					t1[j]++; 
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<t1[i];
		} 
	}
	return 0;
} 
