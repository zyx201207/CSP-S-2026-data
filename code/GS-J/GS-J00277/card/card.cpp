#include<bits/stdc++.h>;
using namespace std;

int main(){
	//forpen(card.in,"r",stdin);
	//forpen(card,out,"w",stdout);
	
	cin>>n>>m;
	s[n]=0
	cin<<s[n];
	for(i=0;i<=n;i++){
		s[n]+=i;
		s[n]=s[n]-s[i];
		while(j<n){
			if(j=i){
				s[n]=0;
			}
		}
	}
	return 0;
}
