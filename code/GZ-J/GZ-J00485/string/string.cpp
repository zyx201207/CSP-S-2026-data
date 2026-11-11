//GZ-J00485 ³Â×ÓÐù 
#include<bits/stdc++.h>
using namespace std;
unsigned long long int n,m[1000000],sum=0,lz,rz;
char c[1000000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m[i]>>c[i];
	}
	int l=1;
	int r=n;
	lz=m[1];
	rz=m[n];
	while(l<r){
		if(lz>rz){
			if(c[l]!=c[r]){
				sum+=min(lz,rz);
			}
			r--;
			lz-=rz;
			rz=m[r];
		}
		else if(lz<rz){
			if(c[l]!=c[r]){
				sum+=min(lz,rz);
			}
			l++;
			rz-=lz;
			lz=m[l];	
		}
		else{
			if(c[l]!=c[r]){
				sum+=min(lz,rz);
			}
			r--;
			l++;
			rz=m[r];
			lz=m[l];
		}
	}
	cout<<sum;
	return 0;
}
