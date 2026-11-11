#include<bits/stdc++.h>
using namespace std;
long long cnt=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin >> n;
	string s1,s2;
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		char ch;
		cin>> ch;
		for(int j=1;j<=k;j++){
			s1=s1+ch;
		}
	}
	
	long long len=s1.size();
	
	for(int i=0;i<len;i++){
		s2[len-i-1]=s1[i];
	}
	
	for(int i=0;i<=len/2;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}
