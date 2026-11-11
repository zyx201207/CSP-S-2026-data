#include <bits/stdc++.h>
using namespace std;
int n,len;
string s;

int hui(){
	int cnt=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
		len+=a;
	}
	int x=hui();
	cout<<x;
	return 0;
}
