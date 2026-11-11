#include<bits/stdc++.h>
using namespace std;
struct area{
	long long data;
	char a;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long all=0;
    for(int i=0;i<n;i++){
		cin>>a[i].data>>a[i].a;
		all+=a[i].data;
	}
	long long len=all/2;
	long long dif=0,lh=0,rh=0;
	long long l=0,r=n-1;
	while(l<r){
		if(lh+a[l].data>len){
			a[l].data-=(len-lh);
			lh=len;
		}
		else
		lh+=a[l].data;
		while(lh>rh){
			if(rh+a[r].data>len){
				if(a[r].a!=a[l].a){
					dif+=(len-rh);
				}
				a[r].data-=(len-rh);
				rh=len;
				break;
			}
			else if(rh+a[r].data>lh){
				if(a[r].a!=a[l].a) dif+=(lh-rh);
				a[r].data-=(lh-rh);
				rh=lh;
				break;
			}
			else if(a[r].a!=a[l].a){
				dif+=a[r].data;
			}
			rh+=a[r].data;
			r--;
		}
		l++;
	}
	cout<<dif;
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
