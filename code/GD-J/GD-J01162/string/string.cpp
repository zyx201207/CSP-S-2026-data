#include<bits/stdc++.h>

using namespace std;

int n,num,o;
string s;
char a;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[200010];
	int n;
	cin>>n;
	int count=0;
	for(int i=1;i<=n;i++){
		cin>>num>>a;
		for(int i=0;i<num;i++){
			
			s[count]=a;
			count++;
		}
	}	
	
	for(int i=0;i<count+1;i++){
		if(s[i]!=s[count-1-i]){
			o++;
		}
	}
	cout<<o/2;
	
	return 0;
} 
