#include <bits/stdc++.h>
using namespace std;
string s;
string pan; 
long long cnt=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int i;
		string a;
		cin>>i>>a;
		
		while(i--){
			s+=a;
		}
	}
	
	if(n==1){
		cout<<0;
		return 0; 
	}
	
	long long l=s.size();
	if(l%2==0){
		long long wa=l/2-1;
		long long wb=l/2;
		while (wa+1){	
			if(s[wa]!=s[wb]){
				cnt++;
			}
			wb++;
			wa--;
		}
	}else{
		long long wa=l/2-1;
		long long wb=l/2+1;
		while (wa+1){
			if(s[wa]!=s[wb]){
				cnt++;
			}
			wb++;
			wa--;
		}
		
	}
	
	cout<<cnt;
	
	
	
	
	
	
	
	return 0;
}
