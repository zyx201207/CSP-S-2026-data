#include<bits/stdc++.h>
using namespace std;
int n,cit,res=0;
string s="";
char cim;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cit>>cim;
		for(int j=1;j<=cit;j++){
			s+=cim;
		}
	}
	for(int j=0;j<=s.size()/2-1;j++){
		if(s[j]!=s[s.size()+1-j]){
			res++;
		}
	}
	cout<<res;
	return 0;
}
