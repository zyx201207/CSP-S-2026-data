//GZ-J00269 凯里学院附属中学 包煜森
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,a;
	long long n,k;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>k>>a;
		for(long long j=0;j<k;j++){
			s+=a;
		}
	}
	long long cnt=0,m=s.size();
	for(long long i=0;i<ceil(m/2);i++){
		if(s[i]!=s[m-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
