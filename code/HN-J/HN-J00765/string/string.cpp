#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,w=0,sum=0;
	cin>>n;
	string s;
	string e; 
	string r;
	for(int i=1;i<=n;i++){
		int a;string b;
		cin>>a>>b;
		w+=a;
		for(int i=0;i<a;i++){
			s=s+b;
			
		}
		
	}
	if(w/2==0){
		for(int i=0;i<w/2;i++){
			e+=s[i];
		}
		for(int i=w/2+1;i<w;i++){
			r+=s[i];
		}
		for(int i=0;i<w/2;i++){
			if(r[i]!=e[i]){
				sum++;
			}
		}
	}
	if(w/2!=0){
		
		for(int i=0;i<w/2;i++){
			e+=s[i];
			
		}
		for(int i=w/2+1;i<w;i++){
			r+=s[i];
			
		}
		for(int i=0;i<w/2;i++){
			if(r[i]!=e[i]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;

}
//Trick||Treat!
