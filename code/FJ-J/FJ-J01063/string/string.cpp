#include<bits/stdc++.h>
using namespace std;
long long a[100005];
char c[100005];
struct node{
	long long l, r, d,f=false;
	char e;
};
node b[1000005];
//map<int,string>
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	if(n<=1){
		cout<<0;
	}
	long long cur=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i].l=cur+1;
		cur+=a[i];
		b[i].r=cur;
		b[i].d=a[i];
		b[i].e=c[i];
	}
	long long l=1,r=n;
	long long ans=0;
	while(l<=r){
		if(b[l].f==false&&b[r].f==false){
			if(b[l].d>b[r].d){
				if(b[l].e==b[r].e){
					b[l].f=true;
					b[l].l+=b[r].d;
				}
				else{
					ans+=b[r].d;
					b[l].f=true;
					b[l].l+=b[r].d;
				}
			}else if(b[l].d==b[r].d){
				if(b[l].e==b[r].e){
					b[l].f=true;
					b[r].f=true;
					l++;
					r--;
				}else{
					ans=ans+b[r].d+b[l].d;
					b[l].f=true;
					b[r].f=true;
					l++;
					r--;
				}
				
			}else{
				if(b[l].e==b[r].e){
					b[r].r-=b[r].d;
					b[l].f=true;
					l++;
				}else{
					ans+=b[r].d;
					b[r].r-=b[r].d;
					b[l].f=true;
					l++;
				}
			}
		}else if(b[r].f==true){
			r--;
		}else if(b[l].f==true){
			l++;
		}
	}
	cout<<min(ans,cur-ans);
	return 0;
}
