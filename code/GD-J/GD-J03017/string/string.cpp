#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,len,ans;
string qw;//×Ü×Ö·û´® 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		string s;
		cin>>num>>s;
		len+=num;
		for(int i=1;i<=num;i++){
			qw+=s;
		}
	}
	if(len%2==0){
		int mid=len/2-1;
		for(int i=0;i<=mid;i++){
			if(qw[i]!=qw[i+mid+1]) ans++;
		}
	}else{
		int mid=len/2;
		for(int i=0;i<mid;i++){
			if(qw[i]!=qw[i+mid+1]) ans++;
		}
	}
	cout<<ans;
	return 0;
} 
