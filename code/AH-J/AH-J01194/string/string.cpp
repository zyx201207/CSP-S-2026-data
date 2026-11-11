#include<bits/stdc++.h>
using namespace std;
long long n,a,sum;
string s,str;
char ch;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a>>ch;
		s.insert(s.size(),a,ch);
	}
	str=s;
	for(int i=0,j=str.size()-1;i<j;i++,j--){
		swap(str[i],str[j]);
	}
	if(str==s){
		cout<<0;
		return 0;
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
