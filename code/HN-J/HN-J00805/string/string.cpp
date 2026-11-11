#include<bits/stdc++.h>
#define it long long
using namespace std;
string s;
it len=0;
char a[200005];
it n,ans=0,c[200005]={0};

int f(int x){
	int i=0;
	while(c[i]>x) i++;
	return i;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=0;i<n;i++){
		it x;cin>>x;len+=x;
		char y;cin>>y;
		for(it i=0;i<x;i++){
			s+=y;
		}
	}
	
	//cout<<s<<endl;
	
	for(it i=len/2;i<len;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	
	cout<<ans;
	
	return 0;
}
