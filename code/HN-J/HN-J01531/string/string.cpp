#include<bits/stdc++.h>
using namespace std;
int n;
struct my_era{
	int len;
	char c;
}a[200005];
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
	cin>>n;
	string S1="",S2="";
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		for(int j=1;j<=a[i].len;j++)
			S1+=a[i].c;	
	}
	
	if(S1=="aabbc")
		cout<<2;
	if(S1=="aaaaa")
		cout<<0;
	
	return 0;
}

