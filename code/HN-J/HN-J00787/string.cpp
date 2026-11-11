#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ac,siz,mid,ans=0;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ac>>c;
		for(int j=1;j<=ac;j++){
			s+=c;
		}
	}
	mid=s.size()/2;
	if(s.size()%2!=1){
		for(int i=mid;i>=1;i--){
			if(s[mid+1-i-1]!=s[mid+i-1]){
				ans++;
			}
		}
	}else{
		for(int i=mid;i>=1;i--){
			if(s[mid-i-1]!=s[mid+i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
