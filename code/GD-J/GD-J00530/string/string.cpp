#include<bits/stdc++.h>
using namespace std;
struct box{
	long long c;
	long long x;
	char s;
}a[200005];
struct node{
	long long l,r;
	char c;
}b[200005];

long long n, s,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0].c=a[0].x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].s;
		s+=a[i].c;
		a[i].x=a[i-1].x+a[i].c;
		if(i==1){
			b[i].l=1;
			b[i].r=a[i].c;
			b[i].c=a[i].s;
		}else{ 
			b[i].l=b[i-1].r+1;
			b[i].r=a[i].x;
			b[i].c=a[i].s;
		}
	} 
	int mid=(s+1)/2;
	for(int i=1;i<=n;i++){
		if(b[i].l>mid){
			break;
		}
		int cl=b[i].l,cr=b[i].r;
		int nr=s+1-b[i].l;
		int nl=s+1-b[i].r;
		for(int j=i;j<=n;j++){
			if(b[j].l<=nl&&nr<=b[j].r){
				if(b[i].c==b[j].c){ 
				}else{
					ans+=b[i].r-b[i].l+1; 
				}
			}
			if(b[j].l<=nl){
				if(b[i].c==b[j].c){ 
				}else{
					ans+=b[i].r-b[j].l+1; 
				}
			}
			if(nr<b[j].r){ 
				if(b[i].c==b[j].c){ 
				}else{
					ans+=b[i].r-b[j].l+1; 
				}
			}
			if(nl<b[j].l&&b[j].r<nr){ 
				if(b[i].c==b[j].c){ 
				}else{
					ans+=b[j].r-b[j].l+1; 
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
