#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,a;
	char c;
	string s;
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int len=s.size();
	int flag=1;
    for(int i=0;i<len/2;i++){
        if(s[i]==s[len-i-1]){
        	continue;
		}else{
			flag=0;
		}
	}
	if(flag==1){
		cout<<0;
	}else{
		cout<<len/2;
	}
	return 0;
}
