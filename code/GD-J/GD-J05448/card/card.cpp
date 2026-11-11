#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	string sa[a]
	for(int i=0;i<a;i++){
		cin>>sa[i];
	}
	string str,st;
	for(int i=0;i<a;i++){
	    int j=str.find(sa[i]);
	    if(j>0){
	    	
	    	str.erase(str[j],str.size()-1-j);
		}
		str.insert(str.size()-1,sa[i]);
		
	}
	
	return 0;
} 
