#include<iostream>
#include<string>
using namespace std;
string s,b;
int main(){
	freopen("card.in","r",stdin);
	feropen("card.out","w",stdout);
	
	int n,m,start=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
		
	}
	for(int i=0;i<n;i++){
		string v;
		v[i]=s[i];
		for(int j=0;j<i;j++){
			if(v[i]==v[j]){
				for(int o=j;o<=i;o++){
					s[o]='*';
				} 
			}
		}
		for(int u=1;u<=n;u++){
			for(int j=1;j<n;j++){
				if(v[j]=u){
					b[i]++;
				} 
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j]!=0){
				cout<<j<<" ";
			}
		}
	}
	return 0;
} 
