#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cout1[4];
	string a,c,
	int b,d;
	cin>>a>>b>>c>>d;
	if(b!='01'&&b!='16'){
		if(d!='01'&&d!='16'){
			cout1[1]=1;
			
			
		}
	    else
	       cout1[1]=0;
		
	}
	else
	  cout1[1]=0;
	if(a[1]==c[1]){
		if(a[2]==c[2]){
		    cout1[2]=1;
			if(a[3]-1==c[3]){
				cout1[4]=1;
				if(a[3]=='d'&&c[3]=='c'){
					cout1[4]=1;
					
					
					
					
					
					
				}
				else
				    cout1[4]=0;
		}
			    
	}
			
		}
		    else
		      cout1[4]=0;
		
		
		
		
	}
	else
	    cout1[2]=0;
	

	cout<<cout1<<endl;
	
	
	return 0;
}
