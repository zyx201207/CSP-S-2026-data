#include<bits/stdc++.h>
using namespace std;
//Trick||Treat! 
long long n,a,len,cnt=0,mid;
string ch;
bool re(string s){
	string ans="";
	for(long long i=s.size()-1;i>=0;i-=1){ans+=s[i];}
	return ans==s;
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s="";
	cin>>n;
	while(n--){
		cin>>a>>ch;
		while(a--){
			s+=ch;
		}
	}
	if(re(s)==1){
		cout<<0;
		return 0;
	}
	len=int(s.size());
	mid=len/2;
	
	if(len%2==0){
		for(long long i=0,j=len-1;i<mid,j>=mid;i++,j--){
			if(s[i]!=s[j])cnt++;
		}
	}
	if(len%2==1){
		for(long long i=0,j=len-1;i<mid,j>mid;i++,j--){
			if(s[i]!=s[j])cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
