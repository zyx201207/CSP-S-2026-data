#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,cnt=0,ans=0;
	char a;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		for(int i=0;i<x;i++){
			s+=a;
		}
		cnt+=x;
    } 
    int t=s[0];
    for(int i=1;i<=cnt;i++){
    	int m=s[i];
    	s[i]=t;
    	t=m;
	}
    if(cnt%2==1){
    	for(int i=1;i<=cnt/2+1;i++){
	        if(s[i]!=s[cnt+1-i]){
	        	s[cnt+1-i]=s[i];
	        	ans++;
			}	
	    }
	}
	else if(cnt%2==0){
		for(int i=1;i<=cnt/2;i++){
			if(s[i]!=s[cnt+1-i]){
				s[cnt+1-i]=s[i];
	        	ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
