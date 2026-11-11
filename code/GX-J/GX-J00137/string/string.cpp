#include<bits/stdc++.h>
using namespace std;

string s,a;

bool backstr(int i,int j){
	while(i<=j){
		if(s[i]!=s[j]){
			return 1;
		}
		
		i++;
		j--;
	}
	
	return 0;
}

int main(){
	// freopen("string1.in","r",stdin);
	// freopen("string1.out","w",stdout);
	
	// freopen("string2.in","r",stdin);
	// freopen("string2.out","w",stdout);
	
	// freopen("string3.in","r",stdin);
	// freopen("string3.out","w",stdout);
	
	// freopen("string4.in","r",stdin);
	// freopen("string4.out","w",stdout);
	
	// freopen("string5.in","r",stdin);
	// freopen("string5.out","w",stdout);
	
	
	char c;
	int n,l=0,lans=0,rans=0,t,i;
	
	cin>>t;
	
	for(i=0;i<t;i++){
		cin>>n>>c;
		for(int j=0;j<n;j++){
			s[j+l]=c;
		}
		l=s.size();
	}
	
	a=s;
	i=0;
	
	while(backstr(0,l)==false){
		if(s[l+i]!=s[l-i]){
			s[l+i]=s[l-i];
			lans++;
		}
		i++;
	}
	
	s=a;
	i=0;
	
	while(backstr(0,l)==false){
		if(s[l+i]!=s[l-i]){
			s[l-i]=s[l+i];
			rans++;
		}
		i++;
	}
	
	if(lans<rans){
		cout<<lans;
	}else{
		cout<<rans;
	}
	
	return 0;
}
