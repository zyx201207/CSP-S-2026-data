#include<bits/stdc++.h>
using namespace std;
long long n,a,k,d;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=d;j<a+d;j++){
			s[j]=c;
		}
		d+=a;
	}
	int j=0;
	if(d%2==1){
		for(int i=d-1;i>d/2;i--){
			if(s[j]!=s[i])k++;
			j++;
		}
	}else{
		for(int i=d-1;i>=d/2;i--){
			if(s[j]!=s[i])k++;
			j++;
		}
	}
	cout<<k;
	return 0;
}
