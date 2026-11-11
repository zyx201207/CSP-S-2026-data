#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+5;
using namespace std;
struct node{
	ll x;
	char y;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll m=0;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y,m+=a[i].x;
	ll cntl=0,cntr=m+1,sum=0;
	for(int i=1,j=n;i<j;){
		//cout<<i<<" "<<j<<"\n";
		//cout<<cntr<<":";
		ll l=cntl+1,r=cntl+a[i].x;//l<=r
		ll u=cntr-a[j].x,v=cntr-1;//u<=v
		ll p=m-l+1,q=m-r+1;//q<=p
		//cout<<cntr<<":";
		//cout<<l<<"-"<<r<<"="<<u<<"-"<<v<<"="<<q<<"-"<<p<<"\n";
	//	if(!(p>=u && q<=v)) j--; 
		//if(cntl+a[i].x>m/2) break;
	//	else if(cntr-a[j].x<m/2) break;
	//	else{
			if(q<=u && v<=p) sum+=(a[i].y!=a[j].y?1:0)*a[j].x,cntr-=a[j].x,j--;//cout<<"[1]\n";
			else if(u<=q && p<=v) sum+=(a[i].y!=a[j].y?1:0)*a[i].x,cntl+=a[i].x,i++;//cout<<"[2]\n";
			else if(q<=u) sum+=(a[i].y!=a[j].y?1:0)*(p-u+1),cntr-=a[j].x,j--;//cout<<"[3]\n";
			else if(p>=v) sum+=(a[i].y!=a[j].y?1:0)*(v-q+1),cntl+=a[i].x,i++;//cout<<"[4]\n";
			
	//	}
		//cout<<sum<<"\n";
	}
	cout<<sum;
	return 0;
}

