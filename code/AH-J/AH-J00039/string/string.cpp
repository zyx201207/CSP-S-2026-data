#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
	long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	int a;
    	char c;
    	cin>>a>>c;
    	for(int i=1;i<=a;i++){
    		s+=c;
		}
	}
	int l=0,r=s.size()-1;
	for(int i=0;i<s.size()/2;i++){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++,r--;
	}
	cout<<cnt;
	return 0;
}
