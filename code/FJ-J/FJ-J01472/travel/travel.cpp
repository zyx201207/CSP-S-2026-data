#include<bits/stdc++.h>
using namespace std;
string n,nn,m,mm;
long long a,b,ns,ms,nns,mms,x,y,o,p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>nn>>m>>mm;
	ns=n.size();
	nns=nn.size();
	ms=m.size();
	mms=mm.size();
	for(int i=0;i<ns;i++){
		a*=10;
		a+=n[i]-'0';
	}
	for(int i=0;i<ms;i++){
		b*=10;
		b+=m[i]-'0';
	}
	for(int i=0;i<nns;i++){
		if(nn[i]<='9' && nn[i]>='0'){
			x*=10;
		    x+=nn[i]-'0';
		}
		if(nn[i]>='A' && nn[i]<='F'){
			o=nn[i]-'A'+1;
		}
	}
	for(int i=0;i<mms;i++){
		if(mm[i]<='9' && mm[i]>='0'){
			y*=10;
		    y+=mm[i]-'0';
		}
		if(mm[i]>='A' && mm[i]<='F'){
			p=mm[i]-'A'+1;
		}
	}
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if((o<=3 && p<=3) || (o>=4 && p>=4)){
		        cout<<1;
		        if(!(o==3 && p==4 || (o==4 && p==3)) && abs(o-p)==1){
			        cout<<1;
		        }
		        else {
			        cout<<0;
		        }
	        }
	        else {
		        cout<<"00";
	        }
	    }
	    else {
		    cout<<"000";
	    }
	}
	else {
		cout<<"0000";
	}
	return 0;
} 
 
