#include<bits/stdc++.h> 
using namespace std;
int n;
long long a[100005],l,r,o;
char b[100005];
long long sum=1,ans;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	if(n==0)cout<<0;
	else {
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(;sum<a[i]+o;sum++){
			s[sum]=b[i];
		}
		o=sum;
	}
	s[0]=b[1];
	for(int i=0;i<=sum;i++){
		cout<<s[i];
	}
if(sum%2==0){
	l=sum/2,r=l+1;
}else {
	r=sum/2;l=r+2;
}
	for(l,r;r<sum;l--,r++){
		if(s[l]!=s[r]){
			char i=s[l];
			s[l]=s[r];
			s[r]=i;
			ans++;
		}
	}
	cout<<ans;	
	}
	
	return 0;
}
