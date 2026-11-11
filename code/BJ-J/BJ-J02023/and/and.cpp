#include<bits/stdc++.h>
using namespace std;
int f(int a,int b){
	string s,s1,sz;
	while(a){
		s+=char(a%2);
		a/=2;
	}
	while(b){
		s+=char(b%2);
		b/=2;
	}
	int sum=0,dsz=max(s.size(),s1.size());
	for(int i=0;i<dsz;i++){
		if(s[i]==s1[i]){
			sz+='1';
		}else{
			sz+='0';
		}
	}
	for(int i=max(s.size(),s1.size());i>0;i--){
		for(int j=0;j<i;j++){
			if(sz[i]==1){
				sum+=2;
			}
		}
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[5005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=f(a[0],a[1]);
	for(int i=0;i<n;i++){
		int smax=f(a[i],a[i+1]);
		if(max<smax){
			max=smax;
		}
	}
	cout<<max;
	return 0;
}
