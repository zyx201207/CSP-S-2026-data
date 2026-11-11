#include<bits/stdc++.h>
using namespace std;
int n,t,h;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int f=0;
	for(int i=1;i<=n;i++){
		
		int x;
		char y;
		cin>>x>>y;
		if(h!=x&&i>=2){
			f=1;
		}
		h=x;
		s+=y;
	}
	int m=s.size();
	if(f==0){
		cout<<0;
		return 0;
	}else{
		if(m%2==0){
			for(int i=1;i<=m;i++){
				if(s[m/2-i]!=s[m/2+i]){
					s[m/2+i]=s[m/2-i];
					t+=1;
				}
			}	
		}else{
			for(int i=1;i<=m;i++){
				if(s[(m-1)/2-i]!=s[(m-1)/2+i]){
					s[(m-1)/2+i]=s[(m-1)/2-i];
					t+=1;
				}
			}
		}
	}
	
	cout<<h*t;
	return 0;
}
