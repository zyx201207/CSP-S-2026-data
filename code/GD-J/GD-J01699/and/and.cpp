#include<bits/stdc++.h>
using namespace std;
long long m,n,p,l,y,sum=1;
struct x{
	long long n;
	int b[50],cd;
};
x a[200010];
bool cmp(x h,x k){
	return h.n >k.n;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(y=0;y<m;y++) cin>>a[y].n;
	sort(a,a+m,cmp);
	int t[50]={0};
	x c,d;
	for(y=0;y<n;y=y+2){
		c=a[y],d=a[y+1];
		for(int i=0;i<min(c.cd,d.cd);i++){
			if(c.b[i]!=d.b[i]) t[i]=0;
			else t[i]=1;
		}
	}
	for(y=0;y<50;y++) sum+=t[y]*pow(2,y);
	cout<<sum;
	return 0;
}

