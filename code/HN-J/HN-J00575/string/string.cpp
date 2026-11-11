#include<bits/stdc++.h>
using namespace std;
long long n;
struct zfc{
	long long num;
	char  zf;
}a[100100];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++ ){
		cin>>a[i].num >>a[i].zf ;
		while(a[i].num --){
			s+=a[i].zf ;
		}
	}
	long long cnt=0;
	long long l=s.size();
	for(long long i=0,j=l-1;i<=l-1,j>=0;i++,j--){
			if(s[i]!=s[j]){
				s[j]=s[i];
				cnt++;
			}
	}
	cout<<cnt;
	
	return 0;
}

