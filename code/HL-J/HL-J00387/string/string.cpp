#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
string s,s1;
long long n,m[100005],a=0; 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>s[i];
	
	} 
	int o=s.size(),l=0;
	for(int i=o;i>=0;i--){
		s1[l]=s[i];
		l++;
	}
	int t;
	for(int i=0;i<o;i++){
    	if(s[i]==s1[i]){
    		t++;
		}
	}
	if(t==o){
		cout<<"0";
	}
	int in=0;
	for(int i=0;i<o;i++){
		if(s[i]!=s1[i]){
			in++;
		}
	}
	cout<<in;
	return 0;
}
