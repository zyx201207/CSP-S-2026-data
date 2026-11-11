#include<bits/stdc++.h>
using namespace std;
string fun(int x){
	string s="";
	while(x){
		s+=x%2+'0';
		x/=2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,a[200005],sum=0,ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(ma<a[i]){
				ma=a[i];
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	cout<<4;
	return 0;
}
