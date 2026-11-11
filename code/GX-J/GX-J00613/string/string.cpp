#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	long long sum=0;
	long long l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]==s[r]){
			l++;
			r--;	
		}	
		else if(s[l]!=s[r]){
			s[r]=s[l];
			sum++;
			continue;
		}	
	}	
	cout<<sum;
    return 0;	
}

