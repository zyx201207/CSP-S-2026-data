#include<bits/stdc++.h>
using namespace std;
long long lev[500005],last=0,is_r=0,t,cont=0;

void s(int n){
	for(int i=0;i<n;i++){
		if(lev[last]<lev[i]){
			t=lev[last];
			lev[last]=lev[i];
			lev[i]=t;
		}
		last=i;
	}
	last=0;
	is_r=0;
	for(int i=0;i<n;i++){
		if(lev[last]<lev[i]){
			is_r=1;
		}
	if(is_r==1){
		s(n);
	}
		last=i;
	}
}
void is_ok(int n,int m){
	for(int i=n/2;i<n;i++){
		if(lev[i]>=lev[n/2]) continue;
		if(m==0) break;
		while(m>=0 && lev[i]<lev[n/2]){
			lev[i]++;
			m--;
		}
	}
	for(int i=0;i<n;i++){
		if(lev[i]==lev[n/2]) cont++;
	}
	cout<<cont;
}
int main(){
	long long n,m;
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>lev[i];
	}
	s(n);
	is_ok(n,m);
	return 0;
} 

