#include<bits/stdc++.h>
using namespace std;
int n;
long long a,cnt=0;
string c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
	}
	for(int i=0;i<a;i++){
		s+=c;
	}
	string t=s;
	reverse(t.begin(),t.end());
	if(s==t){
		cout<<0; 
	}else{
		for(int i=0;i<t.size()/2;i++){
			if(i!=t[0]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
