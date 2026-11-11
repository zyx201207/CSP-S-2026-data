#include<bits/stdc++.h>
using namespace std;
struct w{
	long long a;
	char c;
	long long l;
	long long r;
}b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long m=0;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		b[i].l=m+1;
		m=m+b[i].a;
		b[i].r=m;
	}
	if(m%2==1){
		int f=0;
		long long e,ee,e3,e4;
		for(int i=1;i<=n;i++){
			if((m/2+1)=>b[i].l&&(m/2+1)<=b[i].r){
				e=m/2+1;
				ee=b[i].r-b[i].l+1;
				e3=b[i].r-e;//r
				e4=ee-e3-1;//l
				if(e4==0&&e3==0){
					f=6;
					break;
				}
				if(e4==0){
					f=1
					break;
				}
				if(e3==0){
					f=2
					break;
				}
				if(e3<e4){
					f=3
					e4=e4-e3;
				}else if(e3>e4){
					f=4
					e3=e3-e4;
				}else if(e3==e4){
					f=5
					e3=0;
					e4=0;
				}
				break;
			}
		}
		int ii=e;
		long long h,h2;//l,r
		long long s=0;
		for(int i=e;i>=1;i--){
			if(f==6){
				h=b[i].a;
				h2=b[ii].a;
				if(h==h2){
					if(b[i].c!=b[ii].c){
						s=s+b[i].c;
					}
				}else if(h<h2){
					
				}
			}
		}
	}
	return 0;
}
