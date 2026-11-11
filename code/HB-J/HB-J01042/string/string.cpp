#include <bits/stdc++.h>
using namespace std;
const int maxer=2e5+10;
string reverse(string s,int tot){
	string rs="";
	for(int i=tot-1;i>=0;i--){
		rs+=s[i];
	}
	return rs;
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,toll=0,ans=0;
	long long a[maxer];
	char c[maxer];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		toll+=a[i];
	}
	string s="",rs="";
	for(int i=0;i<n;i++){
		int time=a[i],chars=c[i];
		for(int i=0;i<time;i++){
			s+=chars;
		}
	}
	rs=reverse(s,toll);
	string s1="",rs1="";
	if(toll%2){
		for(int i=0;i<toll;i++){
			if(i==toll/2){
				continue;
			}
			s1+=s[i];
			rs1+=rs[i];
		}
	}
	toll--;
	cout<<s1<<" "<<rs1<<" ";
	string sa,sb;
	for(int i=0;i<toll/2;i++){
		sa+=s1[i];
	}
	for(int i=0;i<toll/2;i++){
		sb+=rs1[i];
	}
	cout<<sa<<" "<<sb<<" ";
	for(int i=0;i<toll/2;i++){
		if(sa[i]!=sb[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
