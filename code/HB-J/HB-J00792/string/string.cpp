#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
string t,s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k>>t;
		for(int j=0;j<k;j++){
			s+=t;
		}
	}
	int le=s.size()/2;
	for(int i=0;i<le;i++){
		if(s[i]!=s[le-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
	
