#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a,b;
	cin>>c1>>a>>s1>>c2>>b>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	else {
		if(a==b){
		    if((s1=="D"&&s2=="F")||(s2=="D"&&s1=="F")){
			    cout<<"1111"<<endl;
		    }
		    else if(s1=="A"&&s2=="B"||s2=="A"&&s1=="B"){
		    	cout<<"1111"<<endl;
	    	}
		    else if(s1=="B"&&s2=="C"||s2=="B"&&s1=="C"){
	    		cout<<"1111"<<endl;
		    }
		    else if((s1=="A"||s1=="B"||s1=="C")&&(s2=="F"||s2=="D")){
		    	cout<<"1100"<<endl;
			}
			else if((s2=="A"||s2=="B"||s2=="C")&&(s1=="F"||s1=="D")){
				cout<<"1100"<<endl;
			}
	        else{
		    	cout<<"1110"<<endl;
		    }
	    }
	    else{
	    	cout<<"1000"<<endl;
		}
	}
	return 0;
}
