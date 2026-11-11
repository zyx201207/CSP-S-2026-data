#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string2.in","r",stdin);
	freopen("string2.out","w",stdout);
	long long cnt=0;
	int n;cin>>n;
	string s="";
	long long len=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		string a;cin>>a;
		len+=x;
		while(x--){
			s+=a;
		}
	}
	if(len<=1){
		cout<<0;
		return 0;
	}
	n--;
	int k;
	if(len%2==1)k=len/2;
	for(int i=0;i<=k;i++){
		if(s[i]!=s[n])cnt++;
		n--;
	}
	
	cout<<cnt;
	return 0;	
}
