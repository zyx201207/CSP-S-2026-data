#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1,c=0;
long long a[500005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	c=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long d=1,q=-1,h=1;
		m=c;
		while(a[i+q]==a[i]&&i+q>=1){
			q--;
			d++;}
		while(a[i+h]==a[i]&&i+h<=n){
			h++;
			d++;}
		while(m>0){
			long long x=a[i]-a[i+q],y=a[i+h]-a[i];
			if(i+q>=1 && i+h<=n){
				if(x<y){
					if(m-x<0) {break;}
					d++;
					m-=x;
					q--;
				}else{
					if(m-y<0) {break;}
					d++;
					m-=y;
					h++;}
			}else if(i+q>=1){
				if(m-x<0) {break;}
				d++;
				m-=x;
				q--;
			}else if(i+h<=n){
				if(m-y<0) {break;}
				d++;
				m-=y;
				h++;	
			}
			else {break;}
		}if(d>s)s=d;
	}cout<<s<<'\n';
	return 0;
}
