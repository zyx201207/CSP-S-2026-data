//GZ-S00424 程茨  黔南州布依族苗族自治州都匀第一中学 
#include<bits\stdc++.h>
using namespace std;
int n,m,a[500010],sum=0,c;
bool qujian(int c){
	if(a[c]==a[c+1])
	  return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
   for(int i=1;i<=n;i++)
	     cin>>a[i];
	   sort(a+1,a+n+1);
	    while(m)	{
	    	for(int i=1;i<=n;i++){
	    	int c=i;
	    	if(qujian(c)){
	    for(int j=c;j>=1;j--){
	    	a[j]=a[j+1];
	    	 m-=a[j+1]-a[j];
	    	  if(a[j]==a[j+1]);
		   }
	     } 	
	   }
  }
		sort(a+1,a+c+1);
	for(int i=1;i<=n;i++){
	   	if(a[i]==a[i+1])
	   	sum++;}
	   cout<<sum;
	   
	return 0;
}
