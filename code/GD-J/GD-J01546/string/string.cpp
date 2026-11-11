#include<bits/stdc++.h>
using namespace std;
long long n,x,l,sum;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x>>a;
		for(int i=1;i<=x;i++,l++){
			s[l]=a;
		}
	}
	if(l%2==0){
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l/2+i])sum++;
		}
	}
	else{
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l/2+i+1])sum++;
		}
	}
	cout<<sum;
	return 0;
}
