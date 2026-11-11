#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int xx;
		string yy;
		cin>>xx;
		cin>>yy;
		for(int j=1;j<=xx;j++){
			s+=yy; 
		} 
	}
	int w=s.size()/2;
	int ans=0;
	for(int i=0,j=s.size()-1;i<w;i++,j--){
		if(s[i]!=s[j]){
			//cout<<s[i]<<" "<<s[j]<<endl;
			ans++;
		}
	}
	cout<<ans<<endl;
	//cout<<s;
	
	return 0;
} 
