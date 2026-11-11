#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long  sum=0;
	for(int i=1;i<=n;i++){
		int t;
		char a;
		cin>>t>>a;
		sum+=t;
		for(int j=1;j<=t;j++)s+=a;
	}
	long long tmp=0;
    if(sum%2==1){
    	for(int i=0;i<(sum-1)/2;i++){
    		if(s[i]!=s[sum-i-1])tmp++;
		}
		cout<<tmp;
	}
	else {
		for(int i=0;i<sum/2;i++){
    		if(s[i]!=s[sum-i-1])tmp++;
		}
		cout<<tmp;
	}
	return 0;
	}

