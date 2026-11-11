#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int id;
		char c;
		cin>>id>>c;
		for(int j=1;j<=id;j++) s+=c;
	}
	int l=s.size();
	string s1;
	string s2;
	for(int i=0;i<l/2;i++) s1+=s[i-1];
	for(int i=0;i<l/2+1;i++) s2+=s[l-i];
	int i=0;
	while(s1!=s2 && i<=l){
		if(s1[i]!=s2[i]){
			s2[i]=s1[i];
			cnt++;
		}
		i++;
	}
	if(cnt!=0) cout<<--cnt;
	else cout<<0;
	return 0;
}
