#include<bits/stdc++.h>
using namespace std;
string str="";
long long n,a,sum=0;
char l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>l;
		for(int j=0;j<a;j++){
			str=str+l;
		}
	} 
	for(int i=0;i<str.size()/2;i++){
		if(str[i]!=str[str.size()-1-i])sum++;
	}
	cout<<sum;
	cout<<endl;
	return 0;
}
