#include<bits/stdc++.h>
using namespace std;
long long n,ra,sum=0,ans=0;
char ch,p[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
   	cin>>n;
   	for(int i=1;i<=n;i++){
   	    cin>>ra;
   	    cin>>ch;
   	    sum+=ra;
   	    for(int i=sum-ra+1;i<=sum;i++){
   	    	p[i]=ch;
   	    	
		}
	}
	for(int i=1;i<=sum;i++){
//		cout<<p[i];
	}
	for(int i=1;i<=sum/2;i++){
		if(p[i]!=p[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
} 
/*
3
2 a
2 b
1 c
*/
