#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
   int n;
   int a[100005];
   string s;
   string c;
   cin>>n;
   for(int i=1;i<=n;i++){
   	cin>>a[i];
   	cin>>s[i];
   }
   int h=1;
   for(int i=1;i<=n;i++){
   	for(int j=1;j<=a[i];j++){
   		c[h]=s[i];
   		h++;
	   }
   }
   for(int i=1;i<=c.length();i++){
   	cout<<c[i];
   }
   int num=0;
   for(int i=1;i<=c.length();i++){
   	for(int j=c.length();j>=1;j++){
   		if(c[i]==c[j]){
   			continue;
		   }
		   else{
		   	num++;
		   }
	   }
   }
   cout<<num;
	return 0;
}
