#include<bits/stdc++.h>
using namespace std;
const int z=5e5+10;
long long a[z],b[z];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a[0]=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=abs(a[i]-a[i-1]);
	}
	long long v=0,s=1;
	long long x=0;
	long long w=2;
	while(w<=n){
		for(long long i=w;i<=n;i++){
			for(long long j=i;j>=w;j--){
				if(b[i]>m){
					break;
				}
				v+=b[i];
				if(b[i+1]==0){
					x+=1;
				}
			}
			if(x!=0){
				x/=(i-1);
			}
			s+=x;
			s+=1;
			if(v==m){
				cout<<s;
				return 0;
			}
			x=0;
		}
		if(v>m){
			w++;
			v=0;
			x=0;
			s=1;
		}
	}
	return 0;
}
