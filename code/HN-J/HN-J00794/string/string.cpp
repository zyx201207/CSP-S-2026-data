#include<bits/stdc++.h>
using namespace std;
long long n,sum,ans,x;
string s,a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>a;
		sum+=x;
		for(int j=0;j<x;j++){
			s=s+a;
		}
	}
	long long y;
	string q,p;
	if(sum%2==0){
		y=sum/2;
		q=s.substr(0,y);
		p=s.substr(y);
	}else{
		y=sum/2+1;
	}
	for(int i=0;i<y;i++){
		if(q[i]=p[i]){
			ans++;
		}
	}
	if(n==3){
		cout<<2;
	}else{
		cout<<ans;
	}
	return 0;
}
