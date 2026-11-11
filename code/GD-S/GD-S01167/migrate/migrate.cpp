#include<bits/stdc++.h>
using namespace std;
int c,t,n,f,hd,fhd;
long long d,a[2000003],cnt;
void s(){
	cin>>n>>d,fhd=hd=1,f=cnt=0,a[n+1]=a[n+2]=LLONG_MAX;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n-1;i;i--){
		if(f){
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i]>d)cnt+=hd,fhd++;
			else if(a[i+1]-a[i]>d)f=0,hd=1;
			else f=0,hd=fhd/*,cout<<fhd<<"!!!\n"*/;
		}
		if(!f){
			/*if(i==5){
				cout<<a[i+1]-a[i]<<' '<<a[i+2]-a[i]<<' '<<a[i+3]-a[i+1]<<' '<<a[i+3]-a[i+2]<<' '<<a[i+3]-a[i]<<'\n';
			}*/
			if(a[i+1]-a[i]>d)f=0,hd=1;
			else if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i+2]<=d&&a[i+3]-a[i]>d)f=1,hd-=2/*,cout<<i<<' '<<hd<<"---\n"*/,cnt+=hd,fhd=2+(a[i+2]-a[i+1]<=d);
			else hd++;
		}
	}
	cout<<cnt<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--)s();
	return 0; 
}
