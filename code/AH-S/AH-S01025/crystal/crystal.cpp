#include<bits/stdc++.h>
#define int long long
#define DBG 0
#define HANDON 1
using namespace std;
int n,m,sum,tmp,a[500005];
int max_last_time,last_time;
main(){
	if(HANDON){freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==1) {cout<<0<<endl;return 0;}
	sort(a+1,a+1+n);
	if(DBG){cout<<"[DEBUG] Sorted a_i=[";for(int i=1;i<n;i++) cout<<a[i]<<",";cout<<a[n]<<"]\n";}
	for(int idx=2;m&&idx<=n;idx++){
		for(int i=1;i<=idx;i++){
			if(a[i]<a[idx]){
				if(m<(a[idx]-a[i])) m=0;
				else m-=(a[idx]-a[i]),a[i]=a[idx];
			}
		}
	}
	if(DBG){cout<<"[DEBUG] Operated a_i=[";for(int i=1;i<n;i++) cout<<a[i]<<",";cout<<a[n]<<"]\n";}
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) max_last_time=max(max_last_time,++last_time);
		else last_time=0;
	}
	cout<<++max_last_time<<endl;
	return 0;
}
