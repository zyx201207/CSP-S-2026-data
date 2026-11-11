#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,ii,mid,jj=1;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	mid=s.size()/2;
	if(s.size()%2==1){
		for(int i=0;i<mid;i++){
			if(s[i]!=s[s.size()-jj]) cnt++;
			jj++;
		}
		cout<<cnt;
		return 0; 
	}
	else if(s.size()%2==0){
		for(int i=0;i<mid;i++){
			if(s[i]!=s[s.size()-jj]) cnt++;
			jj++;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
} 
