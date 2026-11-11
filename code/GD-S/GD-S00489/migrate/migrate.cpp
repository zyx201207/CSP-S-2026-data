#include <bits/stdc++.h>
using namespace std;

int c,t;
int n,d,a[1000010];
bool pd(int a[1000010],int l,int r,int d){
	int b[1000010];
	b[l]=0;
	for(int i=l;i<r;i++){
		if(a[i]+d<a[i+1]){
			return false;
		}
	}
	for(int i=l+1;i<=r && l<i;i++){
		if(a[l]+d>=a[i]){
			b[i]=b[l]+1;
		}else{
			l++;
			i--;
		}
		
	}
	if(b[r-1]==b[r-2]&&b[r-1]!=b[r-3]){
		return true;
	}
	return false;
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ccc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
		}
		for(int l=1;l<=n-2;l++){
			for(int r=l+2;r<=n;r++){
				if(pd(a,l,r,d)){
					ccc++;
				}
			}
		}
		cout<<ccc<<endl;
		
	}
	return 0;
}
