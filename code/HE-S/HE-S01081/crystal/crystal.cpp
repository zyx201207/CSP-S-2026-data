#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N],ave,cnt=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	 // for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	ll x[n]={0};
//	for(int i=1;i<=n;i++) x[i]=x[i-1]+a[i];
//	ave=x[n]/n;
	//cout<<ave;
	sort(a+1,a+n+1);
	 double y=ceil(1.0+n)/2.0;
	 ll z=ceil(y);
	    //cout<<"第二项："<<a[2]<<"\n";
	ave=a[z];
	     //cout<<ave<<"\n";
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	ll *p=lower_bound(a,a+n,ave);
    //cout<<*p<<" ";
	ave=*p;
	   //cout<<"中位数"<<ave<<"\n";
	memset(x,0,sizeof(x));
	//for(int i=0;i<n;i++) cout<<x[i];
	for(int i=1;i<=n;i++) {
		if(a[i]<=ave) x[i]=ave-a[i];
		else x[i]=1e12+1;
	}
	  //for(int i=1;i<=n;i++) cout<<"第"<<i<<"个差值："<<x[i] <<"\n";
	//for(int i=1;i<=n;i++) cout<<x[i]<<" ";
	sort(x+1,x+n+1);
	    //for(int i=1;i<=n;i++) cout<<"第"<<i<<"个差值："<<x[i] <<"\n";
	//for(int i=1;i<=n;i++) cout<<x[i]<<" ";
	ll k=1;
//	while(m>0) {
//		m=m-x[k];
//		cout<<"m"<<k<<":"<<m<<"\n";
//		k++;
//	}
	while(m>=0){
		if(m>=x[k]&&k<=n) {
			cnt++;
			m-=x[k];	
			   //cout<<m<<"\n";		
		}else break;
		k++; 
	}
	cout<<cnt;
	return 0;
}

