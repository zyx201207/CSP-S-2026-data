//GZ_J00372 杨荣睿 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

string cr,sr,cx,sx,r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
    cin>>cr>>sr>>cx>>sx;
    //厢 
	if(cr==cx){
	   cout<<1;
	} else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	//排 
	r=sr[0]+sr[1];
	x=sx[0]+sx[1];
	if(r==x){
		cout<<1;
    }else{
		cout<<0<<0<<0;
		return 0;
	} 
	//侧 
	if(sr[2]=='D'||sr[2]=='F'){
		if(sx[2]=='D'||sx[2]=='F'){
			cout<<1<<1;
			return 0;
		}else{
		cout<<0<<0;
		return 0;
	    } 
    }
	if(sr[2]<='C'&&sr[2]>='A'){
		if(sx[2]<='C'&&sx[2]>='A'){
				cout<<1;	
		}else{
		cout<<0<<0;
		return 0;
	    } 
	}else{
		cout<<0<<0;
		return 0;
	    }
//邻
   if(sr[2]+1==sx[2]||sr[2]-1==sx[2]) cout<<1; 
   else cout<<0;
	return 0;
} 
