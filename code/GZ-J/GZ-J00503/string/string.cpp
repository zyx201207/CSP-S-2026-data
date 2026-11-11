//GZ-J00503 ¶ÅÓÀå·
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	int cnt=0;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		
		for(int j=cnt;j<a+cnt;j++){
			s=s+b;
			
		}cnt+=a;
	}

	long long l=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])
		    l++;
	}
	cout<<l;


return 0;
}
