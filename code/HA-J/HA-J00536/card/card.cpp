#include<bits/stdc++.h>
using namespace std;
long long a[200009],n,m,l,ma;
string s;
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    
   for(int i=1;i<=n;i++){
   	cin>>a[i];
   }
   long long b[100000]={0};
   for(int i=1;i<=n;i++){
   	for(int j=i;j<=n;j++){
   		s+=a[j]+'0';
   		long long a3=0;
   		for(int k=0;k<s.size()-1;k++){
   			if(a[j]==s[k]-'0')a3=k;
		   }
		   if(a3!=0){
		   	string s1="";
		   	for(int k=0;k<=a3+1;k++){
		   		s1+=s[i];
			   }
			   s=s1;
		   }
		   
	   }
	   for(int j=0;j<=s.size();j++){
	   	b[s[j]-'0']++;
	   }
   }
   for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
	
}
