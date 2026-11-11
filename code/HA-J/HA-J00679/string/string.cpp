#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string c;
int m;
char a,cnt;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0,flag=1,shu=0,ll=0;
    cin>>n;
    cin>>m>>a;
    cnt=a;
    shu=m;
    for(int i=m;i>0;i--)
     c+=a;
	for(int i=1;i<n;i++){
		cin>>m>>a;
		shu+=m;
		for(int j=m,k=0;j>0;j--,k++)
		  c+=a;
	}
	int o=shu;
	while(o>0){
	  if(cnt!=c[o])
	   flag=0;
	   o--;
	}
	 if(flag==1){
	 	 cout<<0;
	 	 return 0;
	 }
	 
	for(int i=0,j=shu-1;i<j;j--,i++){
	 		if(c[i]!=c[j])
	 		ll+=1;
		 }
		 cout<<ll;
		return 0;
}
