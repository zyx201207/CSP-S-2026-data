#include<bits/stdc++.h>
using namespace std;
struct S{
	int a;
	string c;
};
S x;
int main(){
	freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    string s1,s2;
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x.a>>x.c;
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=x.a;i++){
			s1+=x.c;
		}
	}
	for(int i=s1.size();i>0;i--){
		s2+=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		for(int j=0;j<s1.size();j++){
			if(s1==s2) break;
			else{
				s2[i]=s1[j];
				cnt++;
			}	
		}
		
	}
	cout<<cnt-1;
	return 0;
}