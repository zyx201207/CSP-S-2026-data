#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string s1,s2;
    int a,b;
    cin>>a>>s1>>b>>s2;
    if(a==b){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    	else{
    		cout<<0<<0<<0;
    		return 0;
    	}if(s1[2]<'D'){
	    	if(s2[2]<'D'){
				cout<<1;
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2])cout<<1;
				else cout<<0;
    		}else cout<<0<<0;
    	}else{
    		if(s2[2]>'C'){
    			cout<<1;
    			if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))cout<<1;
    			else cout<<0;
    		}else cout<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
    	return 0;
    }fclose(stdin);
	fclose(stdout);
	return 0;
}

