#include<bits/stdc++.h>
using namespace std;
string s;
char a;
int n,m,stri,ans,sz;
int main(){
	//ÁîÁîÁîÉêÉêÉêÉêÉêÌá½»Ç°½â³ýÎÄ¼þÊäÈëÊä³ö×¢ÊÍ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--){
		cin>>m>>a;
		sz=s.size();
		for(int i = sz;i < sz+m; i++){
			s+=a;
		}
	}
//	cout<<s<<"\n";
	for(int i = 0; i < s.size()/2; i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
			s[i]=s[s.size()-1-i];
		} 
//		cout<<s[i]<<' '<<s[s.size()-1-i]<<"\n";
	}
	cout<<ans;
}
