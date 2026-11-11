//GZ-J00476 遵义市播州区南白初级中学 卢语宸
#include<bits/stdc++.h>
using namespace std;
	int n;
	long long a[20000005],z;
	char b[20000005];
	string s,s1,s2;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=a[i];j>0;j--){
			s+=b[i];
		}
	}
	long long slen=s.size();
	if(slen%2==0){
		for(int i=0;i<slen;i++){
		if(i<slen/2){
			s1+=s[i];
			}
		if(i>=slen/2){
			s2+=s[i];	
		}
		}			
	}else{
		for(int i=0;i<slen;i++){
		if(i<slen/2){
			s1+=s[i];
			}
		if(i>slen/2){
			s2+=s[i];
		}	
		}
	}
		for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[s1.size()-1-i]){
			z++;
		}
	}
	cout<<z;
	return 0;
}

