#include<bits/stdc++.h> 
using namespace std;
long long n,ans;
long long x;
char c;
string s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		} 
	}	
	long long r=s.size()-1,l=0;
	while(l<=r){
		if(s[l]==s[r]){
			r--;
			l++;
		}else{
			ans++;
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
