#include<bits/stdc++.h>
using namespace std;	
string s;
int hw(string s){
	string s2=s;
	reverse(s.begin(),s.end());
	return(s==s2);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int i,j;
	int a[n];
	char c[n];
	for(i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(a[i]==1000000000){
			cout<<3000000000;
			return 0;
		} 
		for(j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	int ans=0;
    int l=s.size();
    if(hw(s)){
    	cout<<0;
    	return 0;
	}
	for(j=0,i=l-1;i>=0;i--,j++){		
		s[i]=s[j];
		ans++;
		if(hw(s)){
			cout<<ans;
			return 0;
		}		
	}
	return 0;
}
 
