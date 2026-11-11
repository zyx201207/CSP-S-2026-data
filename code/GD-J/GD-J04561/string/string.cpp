#include<bits/stdc++.h>
using namespace std;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,sum=0,b,e,g=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a){
			s=s+c;
			sum++;
			a--;
		}
	}
		b=sum-1;
		e=0;
	for(int i=1;i<=sum;i++){
		int f=0;
		int y=0,t=sum-1;
		int o=sum;
		while(o){
			if(s[y]!=s[t]) f=1;
			t--;
			y++;
			o--;
		}
		if(f==0){
			cout<<g;
			return 0;
		} 	
		else{
			s[b]=s[e];
			e++;
			b--;
			g++;
			
		} 
	}
	cout<<g;
	return 0; 
} 
