#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a;
	string c;
	string s;
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		for(int k=0;k<s.size();k++){
			if(s[i]==s[i+1]){
				break;
			}
			else{
				for(int x=0;x<s.size()/2;x++){
					for(int z=s.size()/2;z>0;z--){
						if(s[k]!=s[z]){
							s[z]=s[k];
							cnt++;
						}
					}
				}	
			}
		}
	}
	cout<<cnt;
	return 0;
} 
