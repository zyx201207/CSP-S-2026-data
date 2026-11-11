#include <bits/stdc++.h>
using namespace std;
const long long mn=500005,mm=1e18;
long long n,m,nl[mn]={},num=0,ab[mn]={};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		long long ma=0;
		for(int i=0;i<n;i++){
			cin>>nl[i];
			ab[nl[i]]++;
			ma=max(ma,ab[nl[i]]);
		}
		cout<<ma;
	}
	else{
	for(int i=0;i<n;i++){
		cin>>nl[i];
		num+=nl[i];
	}
	num/=n;
	for(int i=0;i<n;i++)ab[i]=nl[i]-num;
	sort(ab,ab+n);
	int rw=1;
	while(m!=0){
		if(m>=rw){m-=rw;ab[0]++;}
		else break;
		if(ab[0]==ab[rw])rw++;
	}
	cout<<rw;
}
	return 0;
} 
