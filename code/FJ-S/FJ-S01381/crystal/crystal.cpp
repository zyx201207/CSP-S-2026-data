#include <bits/stdc++.h>
using namespace std;
long long a[500100];
long long b[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,da=0,mida,p=0;
	cin >>n>>m;
	for(int i=0 ; i<n ; i++){
		cin >>a[i];
	}
	sort(a,a+n);
	long long l=a[0]-1,r=a[n-1]+1,mid;
	while(l<=r){
		mid=(l+r+1)/2;
		for(int i=0 ; i<n; i++){
			b[i]=mid-a[i];
		}
		int s=0,w=0;
		for(int i=n-1 ; i>=0 ; i--){
			if(b[i]>=0){
				if(s+b[i]<=m){
					s+=b[i];
					w++; 
				}else{
					s+=b[i];
				}
			}
		}
		if(w>=da){
			mida=mid;
			da=w;
			if(s>=m){
				p=1;
			}else{
				p=-1;
			}
		}
		if(s>=m){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	for(int j=mida+1*p ; j<mida+50*p ; j++){
		for(int i=0 ; i<n; i++){
			b[i]=j-a[i];
		}
		int s=0,w=0;
		for(int i=n-1 ; i>=0 ; i--){
			if(b[i]>=0){
				if(s+b[i]<=m){
					s+=b[i];
					w++; 
				}else{
					s+=b[i];
				}
			}
		}
		da=max(int(da),w);
	}
	cout <<da;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
