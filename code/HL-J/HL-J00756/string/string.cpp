#include<bits/stdc++.h>
using namespace std;
int a,w=0,z,n=0;
string S;
char x;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>a;

for(int i=0;i<a;i++){
	cin>>z>>x;
	for(int q=0;q<z;q++){
	S[w]=x;
	w++;
	
}
}
for(int i=0;i<w;i++){
if(S[i]!=S[w/2+i]){
	n++;
}
}
cout<<n-w/2-1;
return 0;

}