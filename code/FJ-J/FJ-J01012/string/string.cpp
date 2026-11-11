#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long len=0,ans=0;
	char ch[1000000000];
	stack<char> s;
	cin >> n;
	while(n--){
		long long a;
		char c;
	    cin >> a >> c;
	    len+=a;
        for(int i=1;i<=a;i++){
        	s.push(c);
		}		
	}
	for(int i=0;i<len;i++){
        ch[i]=s.top();
		s.pop();		
	}
	int i=0,j=len;
	while(j>i){
	    if(ch[i]!=ch[j]) ans++;
	    i++;
	    j--;
	}
	cout << ans;
	return 0;
} 
