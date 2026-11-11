#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long x,len=0,sum=0;
	string s="",sl,sr;
	char f;
	cin>>n;
	while(n--){
		cin>>x;
		cin>>f;
		len+=x;
		for(int i=1;i<=x;i++){
			s+=f;
		}
	}
	for(int i=0;i<len/2;i++) sl+=s[i];
	for(int i=len/2+1;i<len;i++){
		sr+=s[i];
	}
	for(int i=0;i<len;i++){
		if(sl[i]!=sr[i])sum++;
	}
	cout<<sum;
	return 0;
}
