#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		char b;
		cin>>a>>b;
		for(int i=0;i<a;i++){
			s+=b;
		}
	}
//	cout<<s<<endl;
	long long len=s.size();
//	int mid=len/2;
	long long l=0,r=len-1;
	for(int i=0;i<len/2+1;i++){
		if(s[l]!=s[r]) cnt++;
//		cout<<s[l]<<" "<<s[r]<<endl;
//		cout<<l<<" "<<r<<endl;
		l++,r--;
//		for(int l=0;l<=mid;l++){
//			
//		}
//		for(int r=len;r>=mid;r--){
//			if(s[l]!=s[r]){
//				cnt++;
//			}
//		}
	}
	cout<<cnt<<endl;
	return 0;
}
