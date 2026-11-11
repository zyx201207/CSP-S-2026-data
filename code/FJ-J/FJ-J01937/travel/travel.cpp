#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int ans=0;
		cin>>a>>b>>c>>d;
		if(a==c){
			ans+=1000;
			if(b[1]==d[1]){
			ans+=100;
			if(b[2]<=73&&d[2]<=73){
				ans+=10;
				if(b[2]-d[2]==1||d[2]-b[2]==1){
					ans+=1;
				}
			}
			if(b[2]>73&&d[2]>73){
				ans+=11;
			}
			
			}
		cout<<ans;
		}
		else{
				cout<<"0000";
			} 
	return 0;
} 
