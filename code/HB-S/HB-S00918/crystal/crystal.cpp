#include <bits/stdc++.h>
using namespace std;
long long n,m,p;
long long r;
bool flag;
int ar[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	flag=1;
	cin>>ar[1];
	for(int i=2;i<=n;i++){
		cin>>ar[i];
		if(ar[i]!=ar[i-1]){
			flag=0;
		}
	}
	if(flag==1){
		cout<<n;
		return 0;
	}
	sort(ar+1,ar+n+1);
	p=ar[2]-ar[1];
	if(m<p){
		cout<<0;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(m==i*p){
			cout<<i+1;
			return 0;
		}else if(m<i*p){
			r=m/p+1;
			if(r<i){
				r=i;
			}
			cout<<r;
			return 0;
		}else{
			m-=i*p;
		}
	}
	return 0;
}
