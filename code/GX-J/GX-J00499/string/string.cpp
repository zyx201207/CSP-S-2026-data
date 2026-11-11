#include <bits/stdc++.h>
using namespace std;
char c;
string s="";
int n,sum=0,a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	int temp=s.size();
	for(int i=0;i<temp/2;i++){
		if(s[i]!=s[temp-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
