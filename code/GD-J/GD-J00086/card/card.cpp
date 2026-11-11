#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c[100000];
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,k,p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
		if(a[i-1]<=a[i]){
			p++;
		}
	}
	if(p==n){
		for(int i=1;i<=m;i++){
			cout<<m<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[j]=c[j];
			b[j]=0;
		}
		int o=i;
		for(int j=i;j<=n;j++){
			
			int k=a[j];
			for(int l=i;l<=o-1;l++){
				//cout<<b[l]<<endl;
				if(b[l]==k){
					for(int h=l;h<=o-1;h++){
						b[h]=0;
						o--;
					}
				//	cout<<k;
				}
			}
			b[o]=k;
			o++;
			
		}
		
		for(int j=1;j<=o;j++){
			mp[b[j]]++;
			//cout<<b[j];
		}//cout<<endl;
		
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
} 
