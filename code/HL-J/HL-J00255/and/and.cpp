#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
bool cmp(int x,int y){
	return x>=y;
}
bool epf(int x){
	int p=x;
	while(p>1){
		if(p%2!=0){
			return 0;
		}
		p/=2;
	}
	return 1;
}
int andd(int x,int y){
	int ax[N],ay[N];
	int cntx=0,cnty=0;
	int cnt=0;
	int sumx=0,sumy=0;
	for(int i=x;i>=2;i--){
		if(epf(i)&&i<=x) ax[++cntx]=i,sumx+=i,x-=i;
	}
	for(int i=y;i>=2;i--){
		if(epf(i)&&i<=y) ay[++cnty]=i,sumy+=i,y-=i;
	}
	for(int i=1;i<=cntx;i++){
		for(int j=1;j<=cnty;j++){
			if(ax[i]==ay[j]) cnt+=ax[i];
		}
	}
	if(x-sumx==1&&y-sumy==1) cnt++;
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	bool f2=1;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f=1;
		if(a[i]!=i-1) f2=0;
		if(epf(a[i]+1)==0) flag=0;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n&&f==1){
		cout<<0;
		return 0;
	}
	if(epf(n)==1&&f2==1){
		int cnt=1;
		if(m==2){
			cout<<a[1]-1;
			return 0;
		}
		while(m>=3){
			int x;
			if(m%4==0) x=m/4;
			else x=m/4+1;
			int sum=1;
			for(int i=1;i<=x;i++){
				sum*=2;
			} 
			cnt+=sum;
			if(m%2==0) m/=2;
			else m=m/2+1;
		}
		cout<<a[1]-cnt;
		return 0;
	}
	if(flag){
		cout<<a[n+1-m];
		return 0;
	}
	if(m==2){
		cout<<andd(a[1],a[2]);
	}
	return 0;
}

