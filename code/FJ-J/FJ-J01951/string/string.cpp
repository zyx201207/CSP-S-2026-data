#include<bits/stdc++.h>
using namespace std;
long long n,x,cnt=0;
string s_1,s,y;
int main(){
    cin>>n;
    while(n--){
    	cin>>x>>s_1;
    	while(x--){
    		s+=s_1;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		y+=s[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=y[i])cnt++;
	}
	if(cnt%2==0){
		cout<<cnt/2;
	}else{
		cout<<cnt/2+1;
	}
	return 0;
}
