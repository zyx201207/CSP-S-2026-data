#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string c[100005],s1,s2;
LL len,a[100005],n,mid,r,l,ans=0;
bool flag=false;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>c[i];
		for(int j=1;j<=x;j++){
			s1=s1+c[i];
		}
	}
	len=s1.size();
	s1=" "+s1;
	if(len%2==0){
		flag=true;
		mid=len/2;
		if(s1[mid]!=s1[mid+1]){
			ans++;
			s1[mid]=s1[mid+1];
		}
	}
	else{
		mid=len/2+1;
	}
	
	for(int i=len;i>=1;i--){
		s2=s2+s1[i];
	}
	s2=" "+s2;
	LL cnt1=0,cnt2=0;
	for(int i=1;i<=mid;i++){
		if(s1[i]!=s2[i]){
			cnt1++;
		}
	}
	for(int i=mid+1;i>=len;i++){
		if(s1[i]!=s2[i]){
			cnt2++;
		}
	}
	cout<<ans+min(cnt1,cnt2);
	return 0;
}
