#include<bits/stdc++.h>
using namespace std;
bool check(string l){
int lc=l.size();
if(lc==1)return 1;
else {
for(int i=0,j=lc-1;i<=lc/2-1;i++,j--){
	if(l[i]!=l[j]){
		return 0;
		break;
	}
}
}
return 1;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	int n;
	cin>>n;
int m;char a;string s="";
for(int i=1;i<=n;i++){
	cin>>m>>a;
for(int j=1;j<=m;j++){
	s+=a;
}
}
if(check(s))cout<<0;
return 0;
}
