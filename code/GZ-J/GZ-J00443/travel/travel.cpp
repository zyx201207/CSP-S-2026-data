//GZ-J00443 兴义市弘毅中学 黄昌乾 
#include<bits/stdc++.h>
using namespace std;
string c,s,x,y;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c>>s>>x>>y;
if(c[1]==x[1]&&c[0]==x[0]){
	cout<<1;
}		
else{
	cout<<0;
}
if(c[1]==x[1]&&c[0]==x[0]&&s[0]==y[0]&&s[1]==y[1]){
	cout<<1;
}
else{
	cout<<0;
}
if(c[1]==x[1]&&c[0]==x[0]&&s[0]==y[0]&&s[1]==y[1]&&s[2]+y[2]<='C'+'B'){
	cout<<1;
}
else if(c[1]==x[1]&&c[0]==x[0]&&s[0]==y[0]&&s[1]==y[1]&&s[2]+y[2]>'C'+'F'){
	cout<<1;
}
else{
	cout<<0;
}
if(c[1]==x[1]&&c[0]==x[0]&&s[0]==y[0]&&s[1]==y[1]&&s[2]+y[2]<='C'+'B'&&s[2]-y[2]==1){
	cout<<1;
}
else if(c[1]==x[1]&&c[0]==x[0]&&s[0]==y[0]&&s[1]==y[1]&&s[2]+y[2]<='C'+'B'&&s[2]-y[2]==-1){
	cout<<1;
}
else if(c[1]==x[1]&&c[0]==x[0]&&s[0]==y[0]&&s[1]==y[1]&&s[2]+y[2]>'C'+'F'&&s[2]-y[2]==2){
	cout<<1;
}
else if(c[1]==x[1]&&c[0]==x[0]&&s[0]==y[0]&&s[1]==y[1]&&s[2]+y[2]>'C'+'F'&&s[2]-y[2]==-2){
	cout<<1;
}
else{
	cout<<0;
}
	return 0;
} 
