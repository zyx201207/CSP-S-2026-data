#include<bits/stdc++.h>
using namespace std;
string s,x;
int n,a;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=1;j<=a;j++){	
			s=s+x;
		}
	}
	int l,r,sz=s.size();
	if(sz%2==0){
		l=sz/2-1;
		r=sz/2;
	}
	else{
		l=sz/2-1;
		r=sz/2+1;
	}
	//cout<<s<<endl;
	//cout<<l<<" "<<r<<endl;
	
	while(l>=0){
		if(s[l]!=s[r]) sum+=1;
		l-=1;
		r+=1;
	}
	cout<<sum;
	return 0;
}
