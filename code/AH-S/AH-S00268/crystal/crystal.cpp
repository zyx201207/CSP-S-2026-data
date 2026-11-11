#include<bits/stdc++.h>
using namespace std;
long long m,n,sj=0,sum=0;//n-个数，m-次数
int a[5000001],b[5000001];
int x(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int m1=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-2;i++){
		if(a[i+1]-a[i]<=m){
			int x=a[i+1]-a[i];
			m-=x;
			a[i]+=x;
			x=0;
		}else if(a[i]==a[i+1]&&a[i+2]!=a[i]&&a[i+2]-a[i]<=m/2){
			int x=a[i+2]-a[i];
			m-=x*2;
			a[i]+=x;
			a[i+1]+=x;
			x=0;
		}
		if(m==0||m<a[i+2]-a[i])break;


	}
	sort(a,a+n);
	 a[0]=a[1];
	 int q=a[0];

	for(int i=0;i<n-1;i++){
		if(a[i]==q)sj+=1;

	}
	sort(b,b+n,x);

	//b
	for(int i=0;i<n-1;i++){
		if(b[i]-b[i+1]<=m1){
			int x=b[i]-b[i+1];
			m1-=x;
			b[i+1]+=x;
			x=0;
		}


	}
		sort(b,b+n,x);
	 int r=b[0];

	for(int i=0;i<n;i++){
		if(b[i]==r)sum+=1;

}
	if(sj>sum)cout<<sj;
	else cout<<sum;
	return 0;
}
