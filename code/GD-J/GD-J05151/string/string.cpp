#include<bits/stdc++.h>
using namespace std;
bool hui(string ss){
	long long n1=ss.size();
	long long l1=0,r1=n1-1;
	if(n1==1) return 1;
	while(l1<=r1){
		if(ss[l1]==ss[r1]){
			l1++;
			r1--;
		}
		else return 0;
	}
	return 1;
}
string s;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long a;
	char c;
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(long long i=0;i<a;i++) s+=c;
	}
	
	long long ans=0;
	
	if(hui(s)==1){
		cout<<ans;
		return 0;
	}
	else{
		long long l=0,r=s.size()-1;
		while(l<r){
			if(s[l]==s[r]){
				l++;
				r--;
			}
			else{
				s[r]=s[l];
				l++;
				r--;
				ans++;
			}
			if(hui(s)==1){
				break;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
} 
