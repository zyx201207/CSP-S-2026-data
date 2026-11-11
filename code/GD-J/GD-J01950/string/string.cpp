#include<bits/stdc++.h>
using namespace std;
int n,a[100001],k,y; 
char c[100001][5];
long long s,o;
int l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		scanf("%c%c",&c[i][0],&c[i][1]);
	}
	l=n;
	r=1;
	while(l>r){
		if(c[l][1]!=c[r][1]){
			y=min(a[l],a[r]);
			s=s+y;
			a[l]=a[l]-y;
			a[r]=a[r]-y;
			if(a[l]==0) l--,k++;
			if(a[r]==0) r++;
			
		}
		else {
			y=min(a[l],a[r]);
			
			a[l]=a[l]-y;
			a[r]=a[r]-y;
			if(a[l]==0) l--,k++;
			if(a[r]==0) r++;
		}
		
	}
	cout<<s;
	return 0;
	
} 
