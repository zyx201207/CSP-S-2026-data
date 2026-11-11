#include<bits/stdc++.h>
using namespace std;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	int a;
    	string c;
    	cin>>a;
    	cin>>c;
    	for(int j=1;j<=a;j++){
    		s+=c;
		}
	}
	int x=s.size();
	int m=x/2-1;
	for(int i=0;i<=m;i++){
		if(s[i]!=s[x-1-i]){
			s[i]=s[x-1-i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}