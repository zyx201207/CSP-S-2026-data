#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int i=1,ti=0;
	while(n--){
		int t;
		char a;
		cin>>t>>a;
		for(i;i<=ti+t;i++){
			s+=a;
			//cout<<1<<endl;
		}
		ti=i-1;
	}
	long long flag=1;
	long long as=s[1];
	for(long long i=1;i<=s.size()-1;i++){
		if(as!=s[i]){
			flag=0;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	long long ans=0;
	long long m=s.size()/2;
	long long l=1,r=s.size();
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	//	cout<<1;
	}
	cout<<ans;
	return 0;
}
