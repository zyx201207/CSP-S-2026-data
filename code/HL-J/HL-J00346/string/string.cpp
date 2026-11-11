#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum;
ll len;
string a,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sum>>a;
		len+=sum;
		for(int j=1;j<=sum;j++){
			s+=a;
		}
	}
//	cout<<s<<endl;
	int cnt=0;
	int k=len/2;
	for(int i=0;i<=k;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
//			cout<<i<<" "<<len-i-1<<endl;
//			cout<<s[i]<<" "<<s[len-i-1];
//			cout<<endl;
		}
	}
	cout<<cnt;
	return 0;
}


