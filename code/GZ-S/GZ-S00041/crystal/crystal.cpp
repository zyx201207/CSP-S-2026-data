//GZ-S00041 贵阳市第一实验中学 王果然 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n;
long long m;
int a[N];
int b[N];
int c[N];
int d[N];
int cnt=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	c[1]=1;
	for(int i=2;i<=n;i++){
		if(b[i]*(c[i-1])+d[i-1]<=m){
			c[i]=c[i-1]+1;
			d[i]=b[i]*(c[i-1])+d[i-1];
		}
		else{
		
			d[i]=0;
			cnt=max(cnt,c[i-1]);
			c[i]=1;
		}
	}
	cnt=max(cnt,c[n]);
	cout<<cnt;
	return 0;
}
