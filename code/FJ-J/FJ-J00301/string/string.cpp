#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,len1,len2;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s2;
		len1=len1+a*s2.size();
		for(int j=1;j<=a;j++){
			s1=s1+s2;
		}
	}
	if(len1%2==0)len2=len1/2-1;
	else len2=len1/2;
	ll sum=0;
	//cout<<len2<<" "<<s1<<endl;
	for(int i=0;i<=len2;i++){
		//cout<<s1[i]<<" "<<s1[len1-1-i]<<endl;
		if(s1[i]!=s1[len1-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
