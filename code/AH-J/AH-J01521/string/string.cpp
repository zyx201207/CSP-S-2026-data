#include<bits/stdc++.h>
using namespace std;
const int N=1e8+15;
char b[N];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
int l=0,r=0;
for(int i=1;i<=n;i++){
   int k;
   char a;
   cin>>k>>a;
   l=r+1;
   r+=k;
   for(int i=l;i<=r;i++){
   b[i]=a;
   }
}     
int cnt=0;
for(int i=1;i<=r/2;i++){
	if(b[i]==b[r-i+1]){
		continue;
	}else{
		cnt++;
	}
}
cout<<cnt;
return 0;
} 
