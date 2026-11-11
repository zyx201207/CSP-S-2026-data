#include<bits/stdc++.h>
using namespace std;
void cmp(string s){
    int sum=0;
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]) sum++;
		}
	}
	
	if(s.size()%2!=0){
		for(int i=0;i<(s.size()+1)/2;i++){
			if(s[i]!=s[s.size()-i-1]) sum++; 
		}
	}
     cout<<sum;
}
int main(){
  freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
  long long n;
   cin>>n;
   long long a;char b;
   string s;
   for(int i=1;i<=n;i++){
   	   cin>>a>>b;
   	   for(int j=1;j<=a;j++){
   	   	s+=b;
    	}
   }
   cmp(s);

	fclose(stdin);
    fclose(stdout);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
	return 0;
} 


