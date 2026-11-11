#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
long long d[500005],maxx,h,t;
int ma=1;
bool f,g;
int r;
int main(){
freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
		if(i>2&&!(a[i]-a[i-1]==a[i-1]-a[i-2])){
			g=1;
		}
	}
	d[0]=0,d[1]=0;
	if(!f){
		
		int o=0;
		maxx=sqrt(m);
		for(int i=maxx-5;i<=maxx+5;i++){
			if(((i*i+i)>>1)<=m){
				o=max(o,i);
			}
		}
		int x=(1+o)*o;
		//cout<<o<<' '<<x;
		x/=2;
		if(x<=m){
			cout<<o+1;
		}
		return 0;
	}
	if(!g){
		
		for(int i=1;i<=n;i++){
			h=i*(a[2]-a[1])*(i-1);
			h/=2;
			if(h<=m){
				ma=max(ma,i);
			}else{
				break;
			}
		}
		cout<<ma;
		return 0;
	}
	sort(a+1,a+n+1);
	d[2]=a[2]-a[1];
	for(int i=3;i<=n;i++){
		d[i]=d[i-1]+(a[i]-a[i-1])*(i-1);
	}
	r=2;
	//int cmt;
	for(int l=1;l<=n;l++){
		for(;r<=n;r++){
			
			t=d[r]-d[l]-(l-1)*(a[r]-a[l]);
			if(t>m){
				r++;
				break;
			}
			else
				ma=max(ma,r-l+1);
		}
	}
	cout<<ma;
	//cout<<' '<<cmt;
	return 0;
}
//5 8
// -3 -1 2 2 7
