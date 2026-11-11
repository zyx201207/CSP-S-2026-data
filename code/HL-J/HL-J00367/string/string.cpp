#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	while(n--){
		int m;
		char q;
		cin>>m>>q;
		while(m--){
			s+=q;
		}
	}
	int cnt=0;
	string s1=s.substr(0,s.size()/2);
	if(s.size()%2==0){
		int l=0;
		for(int i=s.size()-1;i>=s.size()/2;i--){
			if(s1[l]!=s[i]){
				cnt++;
			}
			l++;
		}
	}
	if(s.size()%2==1){
		int l=0;
		for(int i=s.size()-1;i>=s.size()/2+1;i--){
			if(s1[l]!=s[i]){
				cnt++;
			}
			l++;
		}
	}
	cout<<cnt;
	return 0;
}
