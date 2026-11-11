#include<bits/stdc++.h>
using namespace std;
long long a,c=0,d=0,n=0;
long long b[10000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[10000];
	cin>>a;
	if(a==0||a==1){
		cout<<"0";
		return 0;
	}
	for(long long i=0;i<a;i++){
		cin>>b[i]>>s[i];
		c+=b[i];
	}for(long long i=0;i<a-1;i++){
		if(s[i]==s[i+1]){
			n++;
		}
	}if(n==a-1){
		cout<<0;
		return 0;
	}for(long long j=0;j<(a/2+1);j++){
		if(s[j]==s[-1-j]){
			d++;
			c-=b[-1-j];
		}
	}
	if(d!=0&&(c==0||c<0)){
		cout<<"0";
	}else{
		if(a%2==1){
			cout<<(c-b[a/2+1])/2;
		}else{
			cout<<c/2;
		}
	}
	return 0;
}
