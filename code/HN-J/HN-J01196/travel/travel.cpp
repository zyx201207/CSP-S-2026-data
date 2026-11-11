#include <bits/stdc++.h>
using namespace std;
struct cx{
	string  cxh,zwh;
	
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cx r,x;
 cin>>r.cxh>>r.zwh>>x.cxh>>x.zwh;
 if(r.cxh==x.cxh){
 	cout<<1;
 }
 else{
 	cout<<0;
 }
 if(r.cxh==x.cxh&&r.zwh[0]==x.zwh[0]&&r.zwh[1]==x.zwh[1]){
 	cout<<1;
 }
 else cout<<0;
 
 if(r.cxh==x.cxh&&r.zwh[0]==x.zwh[0]&&r.zwh[1]==x.zwh[1]&&((r.zwh[2]>'C'&&x.zwh[2]>'C')or(r.zwh[2]<='C'&&x.zwh[2]<='C'))){
 	cout<<1;
 }
 else cout<<0;
 
  if(r.cxh==x.cxh&&r.zwh[0]==x.zwh[0]&&r.zwh[1]==x.zwh[1]&&((r.zwh[2]>'C'&&x.zwh[2]>'C')or(r.zwh[2]<='C'&&x.zwh[2]<='C'))&&(char(r.zwh[2]+1)==x.zwh[2] or char(r.zwh[2]-1)==x.zwh[2])){
 	cout<<1;
 }
 else{
 	cout<<0;
 }
 
	
	
	
	return 0;
}
