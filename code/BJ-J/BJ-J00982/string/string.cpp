#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin>>a;
    long long cnt=0;
    string s1,s2="";
    while(a--){
		int shu;
		cin>>shu>>s1;
		while(shu--){
			s2+=s1;
		}
	}
	for(int i=0;i<s2.size();i++){
		int j=s2.size()-1-i;
		if(s2[i]!=s2[j]&&i<j) cnt++;
		if(i>=j) break;
	}
	cout<<cnt;
    return 0;
}
