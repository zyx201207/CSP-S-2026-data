#include<bits/stdc++.h>
#include<string>
using namespace std;
int n；
long long t,l[20005],x,y=1;
char m[20005],c[20005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>m[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l[i];j++){
			s=s+m[i];
		}
	}
	 x=s.size();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l[i];j++){
			c[y]=m[i];
			y++;
	}
}
	for(int i=1;i*2<=x;i++){
		if(c[i]!=c[x-i+1]){
			t++;
			}
	}
	cout<<t;
}
