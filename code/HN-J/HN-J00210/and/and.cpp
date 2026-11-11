#include<bits/stdc++.h>
using namespace std;
int n,m,sun=1;
long long a[200010],o[40],p,t=1;
map<long long,bool>tong;
bool mop(int l,int k){
	return l>k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=30;i++){
		o[i]=pow(2,i);
	}
	sort(a+1,a+n+1,mop);
	p=a[1];
	for(int i=1;i<=n;i++){
		bool u=0;
		for(int j=0;j<=30;j++){
			if(o[j]>p)break;
			if(o[j]==p){
				u=1;
				break;
			}
		}
		if(a[i]!=p&&u){
			p=a[i];t++;	
		}
	}
	for(int i=t+1;i<=n;i++){
		int u=0;
		for(int j=0;j<=30;j++){
			if(o[j]>a[i])break;
			if(o[j]==a[i]){
				u=1;
				break;
			}
		}
		if(!u&&a[i]!=0){
			p=(p&a[i]);
			tong[a[i]]=1;
			sun++;
		}
		if(sun==m)break;
	}
	if(sun!=m){
		for(int i=n;i>=2;i--){
			if(tong[a[i]]==0)p=(p&a[i]);
		}
	}
	cout<<p;
	return 0;
}

