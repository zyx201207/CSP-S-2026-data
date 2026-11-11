#include <iostream>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	string s1,s2;
	int he=1;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		char c;cin>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
		he+=a;
	}
	if(he/2!=0){
	for(int i=0;i<(he-2)/2+1;i++){
		s1+=s[i];
	}for(int i=he-2;i>=(he-2)/2+1;i--){
		s2+=s[i];
	}int ans=0;
		for(int i=0;i<he/2;i++){
			if(s1[i]!=s2[i]){
				ans++;}
		}cout<<ans;
	}
	
	
		if(he/2==0){
	for(int i=0;i<(he-2)/2-1;i++){
		s1+=s[i];
	}for(int i=he-2;i>=(he-2)/2+1;i--){
		s2+=s[i];
	}int ans=0;
		for(int i=0;i<(he-2)/2;i++){
			if(s1[i]!=s2[i]){
				ans++;}
		}cout<<ans;
	}
		
		
	return 0;
}
 
