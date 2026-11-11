#include<bits/stdc++.h>;
using namespace std;

int main(){
	//forpen(and.in,"r",stdin);
	//forpen(and,out,"w",stdout);
	
	cin>>n>>m;
	endl;
	s[n]=0;
	for(int i=0;i<=s[n];i++){
		s[n]+=s[n+i];
		cout<<s[n+i];
		while(i<n){
			s[n]&s[n+1];
			while(j<n&&j>i){
				cout<<j;
				j=j+1;
			}
		}
	}
	return 0;
}





