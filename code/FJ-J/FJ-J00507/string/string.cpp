#include<bits/stdc++.h>
using namespace std;
int n,num=0,cmp=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		num+=a;
		while(a--){
			s+=c;
		}
	}
	num--;
	if(num%2==0){
		int j=num/2;
		for(int i=0;i<j;i++){
			if(s[i]!=s[num])cmp++;
			num--;
		}
	}else{
		int j=(num+1)/2;
		for(int i=0;i<j;i++){
			if(s[i]!=s[num])cmp++;
			num--;
		}
	}
	cout<<cmp;
	return 0;
}
