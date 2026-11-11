#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
char c;
int shu,ans=1e9,n;
string s;
int huiwen(string x){
	int l=0,len=x.size();
	while(l<len){
		if(x[l]!=x[len-l-1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>shu>>c;
		string a="";
		for(int j=0;j<shu;j++){
			a[j]=c;
		}
		s=s+a;
	}
	if(huiwen(s)){
		cout<<"0";
	}else{
		cout<<"1";
	}
	return 0;
}
