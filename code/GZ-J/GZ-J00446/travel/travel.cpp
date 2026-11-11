//GZ-J00446  王靖吉  遵义市第一初级中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b,c,d;
	 cin>>a>>b>>c>>d;
	 if(a==c){
	 	cout<<1;
	 }
	 else{
	 	cout<<0;
	 }
	 int n[2],m[2];
	 for(int i=0;i<2;i++){
	 	n[i]=b[i];
	 	m[i]=d[i];
	 }
	 for(int j=0;j<2;j++){
	 	if(n[j]!=m[j]){
	 		cout<<0;
	 		break;
		 }
		 if(n[j]==m[j]){
		 	if(n[j+1]==m[j+1]){
		 	cout<<1;
			 break;	
			 }
		 }
	 }
	 int z[0],x[0];
	 for(int f=1;f<2;f++){
	 	z[f]==b[f];
	 	x[f]==d[f];
	 }
	 for(int h=0;h<1;h++){
	 	if(z[h]=='A'||'B'||'C'&&x[h]=='A'||'B'||'C'){
	 		cout<<1;
	 		break;
		 }
		 if(z[h]=='A'||'B'||'C'&&x[h]=='D'||'F'||z[h]=='D'||'F'&&x[h]=='A'||'B'||'C'){
		 	cout<<0;
		 	break;
		 }
	 }
	 cout<<1; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

