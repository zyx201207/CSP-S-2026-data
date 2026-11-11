#include<bits/stdc++.h>
using namespace std;
long long m,n;
int same[100005];
int a[100005];
int same1[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int o=0;
	int zd1=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>zd1){
			zd1=a[i];
		}
		for(int j=i;j>=1;j--){
			
			if(a[i]==a[j]){
				int pd=1;
				for(int p=1;p<=o;p++){
					if(a[i]==a[p]){
						same[p]++;
						same1[p]=a[i];
						pd=0; 
					}
				}
				if(pd==1){
					o++;
					same[o]=2;
					same1[o]=a[i];
				}
			}
		}

		
	}
	cout<<zd1;
	return 0;
}
