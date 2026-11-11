#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,ans=0,num=0,qaq=0;
	string m,n;
	cin>>a>>m>>b>>n;
	if(a==b){
		num=1;
	}else{
		num=0;
	}
	cout<<num;
	int p=m.length();
	for(int i=0;i<p-1;i++){
		if(num==1){
		    if(m[i]==n[i]){
			    ans=1;
		    }else{
			    ans=0;
		    }
	    }else{
	    	ans=0;
		}
	}
	cout<<ans;
	if(ans==1){
		if(m[2]=='A'){
    		if(n[2]=='B' || n[2]=='C'){
				qaq=1;
			}else{
			    qaq=0;
			}
		}
		if(m[2]=='B'){
			if(n[2]=='A' || n[2]=='C'){
				qaq=1;
			}else{
				qaq=0;
			}
		}
		if(m[2]=='C'){
			if(n[2]=='A' || n[2]=='B'){
				qaq=1;
			}else{
				qaq=0;
			}
		}
		if(m[2]=='D'){
			if(n[2]=='F'){
				qaq=1;
			}else{
				qaq=0;
			}
		}
		if(m[2]=='F'){
			if(n[2]=='D'){
				qaq=1;
			}else{
				qaq=0;
		    }
		}
	}else{
	    qaq=0;
	}
	cout<<qaq;
	if(qaq==1){
		if(m[2]=='A'){
			if(n[2]=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
		if(m[2]=='B'){
			cout<<"1";
		}
		if(m[2]=='C'){
			if(n[2]=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
		if(m[2]=='D'){
			cout<<"1";
		}
		if(m[2]=='F'){
			cout<<"1";
		}
	}else{
		cout<<"0";
	}
	return 0;
}