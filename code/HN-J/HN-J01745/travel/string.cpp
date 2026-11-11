#include <bits/stdc++.h>
using namespace std;
long long m[100001];
char c[100000001];
string s;
int main(){
	//freopen(".in","r",stdin);
	//fropen(".out","w",stdout);
	int n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>m[i]>>c[i];
		for(long long j=0;j<m[i];j++){
			s+=c[i];	
		}
	}
	long long len=s.size();
	int ans=0;
	if(len%2==1){
		long long od=len-1;
		for(long long i=0;i<=s.size()/2;i++){
			if(s[i]!=s[od]){
				ans++;
			}
			od=od-2;
		}
	}else{
		long long er=len-1;
		for(long long i=0;i<=s.size()/2;i++){
			if(s[i]!=s[er]){
				ans++;
			}
			er=er-2;
		}
	}
	cout<<ans;
}
