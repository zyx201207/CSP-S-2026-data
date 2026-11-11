#include<bits/stdc++.h>
using namespace std;
string kill(string s,int a,int b){
	for(int i=a;i<=b;i++){
		s[i]='*';
	}
	string d="";
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]!='*'){
			d+=s[i];
		}
	}
	return d;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int card[10000];
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	string s;
	for(int i=1;i<=m;i++){
		s="";
		for(int j=1;j<=n;j++){
			for(int k=0;k<j;k++){
				if(s[k]==(char)card[j]){
					s=kill(s,k,n);
					
				}
				s+=(char)card[j]; 
			}
		}
		int len=s.size(),ans=0;
		for(int j=0;j<len;j++){
			if(s[j]==i)ans++;
		}
		cout<<ans<<" ";
		
	}
	return 0;
}
/*10 3
 3 1 2 1 3 2 3 1 2 1*/
 /*
 4 3
 1 2 1 3*/
