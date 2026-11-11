#include<bits/stdc++.h>
using namespace std;
long long s1,s2; 
string a,b,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a>>c2>>s2>>b;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(a=="A"){
			    if(b=="B"||b=="C"){
			        cout<<1; 
			        if(b=="B"){
			        	cout<<1;
				    }else{
				    	cout<<0;
					}
			    }else{
			    	cout<<0<<0;
				}
		    }else if(a=="B"){
			    if(b=="A"||b=="C"){
			        cout<<1;
					cout<<1; 
			    }else{
			    	cout<<0<<0;
				}
		    }else if(a=="C"){
			    if(b=="A"||b=="B"){
			        cout<<1;
					if(b=="B"){
			        	cout<<1;
				    }else{
				    	cout<<0;
					} 
			    }else{
			    	cout<<0<<0;
				}
		    }else if(a=="D"){
			    if(b=="E"){
			        cout<<1<<1; 
			    }else{
			    	cout<<0<<0;
				}
		    }else if(a=="E"){
			    if(b=="D"){
			        cout<<1<<1; 
			    }else{
			    	cout<<0<<0;
				}
		    }else{
			   cout<<0;
		    }
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;	
}
