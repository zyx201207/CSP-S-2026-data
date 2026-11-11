#include<bits/stdc++.h>
using namespace std;
string s;
int n,x,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		char c;	
		cin>>x>>c;
		for(int i=1;i<=x;i++)s+=c;
	}
	int mid=(s.size()-1)/2+1;
	if(s.size()%2){
		for(int i=0;i<mid-1;i++){
			if(s[i]!=s[s.size()-i-1]){
				ans++;
			}
		}
	}
	else {
		for(int i=0;i<mid;i++){
			if(s[i]!=s[s.size()-i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
