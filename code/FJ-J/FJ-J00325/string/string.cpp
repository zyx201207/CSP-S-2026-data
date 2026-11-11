#include<bits/stdc++.h>
using namespace std;
string s[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,v=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string l;
		cin>>x>>l;
		v+=x;
		for(int j=1;j<=x;j++){
			s[i+j+cnt]=l;
		}
		cnt++;
	}
	int o=0;
	int d=v;
	int u=0;
		while(d-1){
			if(s[u+2]!=s[v+1-u]){
				o++;
			}		
			d-=2;
			u++;	
		}
	
	cout<<o;
	return 0;
}
