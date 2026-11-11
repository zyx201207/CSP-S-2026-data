#include<bits/stdc++.h>
using namespace std;
int n,x,t,cnt,sum;
string s;
char l,h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>l;
		for(int j=1;j<=x;j++){
			s[t++]+=l;
		}
	}
	int i=0;
	while(i<t/2){
		if(s[i]!=s[t-i-1]){
			cnt++;
		}
		i++;
	}
	cout<<cnt;
	return 0;
}


