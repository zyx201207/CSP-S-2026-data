#include <bits/stdc++.h>
using namespace std;
long long n,a,len,num;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		char c;
		cin>>a>>c;
		for(long long j=len;j<len+a;j++){
			s[j]=c;
		}
		len+=a;
	}
	long long left=0,right=len-1;
	for(long long i=0;i<len;i++){
		if(s[left]!=s[right]){
		   num++;
		}
		left++;
		right--;
		if(left>=right){
			break;
		}
	}
	cout<<num;
	return 0;
}
