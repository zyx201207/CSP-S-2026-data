#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct stu{
	long long k;
	char a;
}a[222222];
struct uts{
	long long k;
	char a;
}b[222222];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].k>>a[i].a;
		b[n-i+1].k=a[i].k;
		b[n-i+1].a=a[i].a;
	}
	long long x=1,y=1;
	long long l=a[1].k,r=b[1].k;
	while(1){
		if(a[x].a==b[y].a){
			if(l>r){
				y++;
				l-=r;
				r=b[y].k;
			}
			else if(l<r){
				x++;
				r-=l;
				l=a[x].k;
			}
			else{
				x++;
				y++;
				l=a[x].k;
				r=b[y].k;
			}
		}
		else{
			if(l>r){
				ans+=r;
				y++;
				l-=r;
				r=b[y].k;
			}
			else if(l<r){
				ans+=l;
				x++;
				r-=l;
				l=a[x].k;
			}
			else{
				ans+=l;
				x++;
				y++;
				l=a[x].k;
				r=a[x].k;
			}
		}
		if(x==y&&x==n){
			if(a[x].a==b[y].a){
				if(l>r){
					y++;
					l-=r;
					r=b[y].k;
				}
				else if(l<r){
					x++;
					r-=l;
					l=a[x].k;
				}
				else{
					x++;
					y++;
					l=a[x].k;
					r=b[y].k;
				}
			}
			else{
				if(l>r){
					ans+=r;
					y++;
					l-=r;
					r=b[y].k;
				}
				else if(l<r){
					ans+=l;
					x++;
					r-=l;
					l=a[x].k;
				}
				else{
					ans+=l;
					x++;
					y++;
					l=a[x].k;
					r=a[x].k;
				}
			}
			break;
		}
	}cout<<ans/2;
	return 0;
}
