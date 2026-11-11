#include<bits/stdc++.h>
using namespace std;
struct zf{
	long long s;
	char z;
}li[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>li[i].s>>li[i].z;
		sum+=li[i].s;
		li[i].s=sum;
	}
	int l,r;
	l=sum/2+1;
	r=sum-l+1;
	int ans=0;
	while(l!=0){
		char zl,zr;
		for(int i=0;i<=n;i++){
			if(l<=li[i].s){
				zl=li[i].z;
				break;
			}
		}
		for(int i=0;i<=n;i++){
			if(r<=li[i].s){
				zr=li[i].z;
				break;
			}
		}
		if(zr!=zl) ans++;
		l--;
		r++;
	}
	cout<<ans;
	return 0;
}
