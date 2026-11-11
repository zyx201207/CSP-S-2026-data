#include <bits/stdc++.h>
using namespace std;
long long n;
string s[10000010];
long long len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char q;
	long long a=0;
	for(int i=0;i<n;i++){
		cin>>a>>q;
		for(int j=len;j<=a+len-1;j++){
			s[i]=q;
		}
		len+=a;
	}
	long long num=len-1;
	long long sum=0;
	for(int i=0;i<=len/2-1;i++){
		if(s[i]==s[num]){
			num--;
		}else{
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0; 
}
