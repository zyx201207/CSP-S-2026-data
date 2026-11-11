#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
	int n;
	cin>>n;
	string s;
	while(n--){
        long long x;
        char a;
        cin>>x>>a;
        while(x--){
            s+=a;
        }
	}
	int ans=0;
	for(int i=0;i<(s.size()-1)/2;i++){
        if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
