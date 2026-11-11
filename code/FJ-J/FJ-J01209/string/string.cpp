#include<bits/stdc++.h>
using namespace std;
int n,a,c,b;
string s1;
string s2;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	int j,i;
	cin>>n;
	for(int i=0;i<=n+1;i++){
		cin>>s1[i];
	}
	for(int j=0;j<=n/2-1;j+2){
	for(int i=0;i<=s1[j];i++){
		s2+=s1[j-1];
	}
}
	a=s2.size();
	for(int i=a/2;i>=0;i--){
		c=s2[i];
		for(int j=0;j<=a/2;j++){
			b=s2[j];
		}
		if(c=b)a--;
	}
	cout<<a;
	return 0;
}
