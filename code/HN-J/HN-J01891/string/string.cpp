#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,mi=0x3f3f3f3f,mx=-0x3f3f3f3f;
string s;
int b[130];
bool f(char t){
	for(int i=0;i<s.size();i++){
		if(s[i]!=t) return 0;
	}
	return 1;
}
bool h(){
	string s1;
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
return s1==s;
}
int main(){
	  freopen("string.in","r",stdin);
      freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x;
		cin>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	if(f(s[1]) || h()){
	cout<<0;
	return 0;
}
    for(int i=0;i<s.size();i++){
    	b[int(s[i])]++;
	}
	for(int i=1;i<=130;i++){
		mx=max(mx,b[i]);
	}
	int j=s.size()-mx;
	mi=min(mi,j);
	string s2=s;
	for(int i=0;i<s.size();i++){
		int j=i;
		while(j--){
			for(int k=0;k<s2.size();k++){
				for(int l=int('a');l<=int('z');l++){
					s2[k]=char(l);
					if(h()) break;
				}
			}
		}
	}
	int num=0;
	for(int i=0;i<s2.size();i++){
		if(s[i]!=s2[i]) num++;
	} 
	mi=min(mi,num);
	cout<<mi;
	return 0;
}
