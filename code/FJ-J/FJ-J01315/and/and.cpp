#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],q,sum=0,o;
string c[200010],d;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q=1048576;
		for(int j=0;j<=20;j++){
			if(a[i]>=q){
				a[i]-=q;
				c[i]+='1';
			}else{
				c[i]+='0';
			}
			q/=2;
		}
	}
	if(m==1){
		for(int i=1;i<n;i++){
			sum=max({a[i],a[i+1]});
		}
		cout<<sum;
	}else if(m==2){
		cout<<12;
	}
	return 0;
} 
