#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
    //	cout<<c1<<s1<<c2<<s2;
	if(c1==c2){
	    cout<<1;
	    char s3,s4;
	    s3=s1[2];
	    s4=s2[2];
    //	cout<<s1<<s2;
	    s1[2]=0;
	    s2[2]=0;
	    int a=s3;
        int b=s4;
        a-=64;
        b-=64;
        //cout<<a<<b<<"/";
	    if(s1==s2){
		    cout<<1;
		    if(a<4 && b<4){
			    cout<<1;
	    	}else{
    		cout<<0;
	    	}
	    }else{
	    	cout<<0<<0;
    	}

        if(a-b==1 || b-a==1){
        	if(a==3 && b==4){
        		cout<<0;
	    	}else if(a==4 && b==3){
	    		cout<<0;
    		}else{
    			cout<<1;
    		}
        	
    	}else{
	    	cout<<0;
	    }
	}else{
		cout<<0<<0<<0<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
