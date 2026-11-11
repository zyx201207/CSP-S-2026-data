#include<bits/stdc++.h>

using namespace std;
struct str{
	long long num;
	char name;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	str s[100010];
	long long n,ans=0,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].num >>s[i].name ;
		ans=ans+s[i].num ;
	}
	long long l;
    l=(ans+1)/2;
    for(int i=1;i<=(n+1)/2;i++){
    		if(s[i].name !=s[n-i+1].name ){
    			if(s[i].num >=s[n-i+1].num ){
    				m=m+s[n-i+1].num ;
    				s[n-i].num =s[n-i].num +s[n-i+1].num -s[i].num ;
    				if(s[n-i].name =!s[i].name )m=m+s[i].num -s[n-i+1].num ;
				}
				else{
					m=m+s[i].num ;
    				s[i+1].num =s[i+1].num +s[i].num -s[n-i+1].num ;
    				if(s[i+1].name =!s[n-i+1].name )m=m+s[n-i+1].num -s[i].num ;
				}
			}
			else{
				if(s[i].num >=s[n-i+1].num ){
    				s[n-i].num =s[n-i].num +s[n-i+1].num -s[i].num ;
    				if(s[n-i].name =!s[i].name )m=m+s[i].num -s[n-i+1].num ;
				}
				else{
					s[i+1].num =s[i+1].num +s[i].num -s[n-i+1].num ;
    				if(s[i+1].name =!s[n-i+1].name )m=m+s[n-i+1].num -s[i].num ;
				}
			}
		
	}
    cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
