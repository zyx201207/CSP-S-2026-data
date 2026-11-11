#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
string s;
long long t=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char c;
		cin>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	int b=s.size();
	if(b%2==0){
		int j=0;
		for(int i=0;i<s.size()/2;i++){
			if(s[s.size()/2-1-j]!=s[s.size()/2+j]){
				t++;
			}
			j++;
		}
	}else{
		int j=0;
		for(int i=0;i<s.size()/2;i++){
			if(s[s.size()/2-1-j]!=s[s.size()/2+j]){
				t++;
			}
			j++;
		}
		
	}
	cout<<t;
	return 0;
} 
