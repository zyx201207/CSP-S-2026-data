#include<bits/stdc++.h>
using namespace std;
int n;
long long x=0;
long long a;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	string t;
	if(n%2==0){
		for(int i=n/2;i>=1;i--){
			t+=s[i];
		}
		for(int i=n/2;i<=n;i++){
			if(t[i]!=s[i]){
				x++;
			}
		}
	}else{
		for(int i=n/2;i>=1;i--){
			t+=s[i];
		}
		for(int i=n/2+1;i<=n;i++){
			if(t[i]!=s[i]){
				x++;
			}
		}	
	}
	
	cout<<x;
	return 0;
} 
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
