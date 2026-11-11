#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k;
	char a[100005]={},b[100005];
	string s="";
	cin>>n;
	long long cnt=0,cnt1=0;
	for(int i=1;i<=n;i++){
		cin>>k>>a[i];
		for(int i=1;i<=k;i++){
			s+=a[i];
		} 
	}
	for(int i=0;i<s.size();i++){
		if(i>=s.size()/2){
			if(s[i]!=s[n-i]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
