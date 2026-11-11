#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],c=0,mp,o[500001],ans=0,l=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>m){
		mp=m;
	}
	else{
		mp=n;
	}
	for(int i=0;i<mp;i++){
		c++;
		for(int j=0;j<n;j++){
			b[j]=a[j];
		}
		for(int e=c;e<mp;e++){
			for(int j=i+1;j<n;j++){
				if(b[e]==b[j]&&b[e]!=0){
					for(int k=e;k<j-1;k++){
						b[k]=0;
					}
				}
			}
		}
		for(int k=0;k<mp;k++){
			if(b[k]==i){
				o[l]=i;
				l++;
			}
		}
	}
	for(int j=1;j<=mp;j++){
		for(int i=1;i<=l;i++){
			if(o[i]==j){
				ans+=1;
			}
		}
		cout<<ans<<" ";
		ans=0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
