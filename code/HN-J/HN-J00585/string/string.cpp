#include<iostream>
#include<string>
using namespace std;
const int N=+5;
long long n;
long long  cnt;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	for(long long i=1;i<=n;i++){
		double a;
		char b;
		cin>>a>>b;
		for(long long j=len;j<len+a;j++){
			s[j]=b;
		}
		len+=a;
		
	}
	for(int i=0,j=len/2+(len%2==1);i<len/2,j<len;i++,j++){
		if(s[i]!=s[j]) cnt++;
	}
	cout<<cnt;
	return 0;
} 


/*
abcdefghijklmnopqrstuvwxyz
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
    _
  (           )
  *    (	   )
(	*  )
 ( * *)
  ( _)

*/
