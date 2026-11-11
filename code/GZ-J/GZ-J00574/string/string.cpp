// GZ-J00574  遵义市第十一中学 黄炼超
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum;
	string m;
	string s="";
	int all=0;
	for(int i=0;i<n;i++){
		cin>>sum>>m;
		for(int i=0;i<sum;i++){
			s=s+m;
		}
	}
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				all++;
			}
		}
	}
	else{
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				all++;
			}
		}
	}
	cout<<all;
	return 0;
}

