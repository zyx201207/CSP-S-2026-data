#include<bits/stdc++.h>
using namespace std;
string s;
int gz(int len){
	int last=s.size();
	int cnt=0;
	for(int i=0;i<len;i++){
	if(s[i]!=s[last]){
		cnt++;
	}
	last--;
}
return cnt;
}
int gy(int len){
	int last=s.size();
	int cnt=0;
	int first=0;
	for(int i=len+1;i<=last;i++){
	if(s[i]!=s[first]){
		cnt++;
	}
	first++;
}
return cnt;
}
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    int n;
    string c;
    bool flag=1;
   	long long a;
   	string b;
   	long long len=0;
   	cin>>n;
	for(int i=1;i<=n;i++){ 
	cin>>a>>b;
	len+=a;

        for(int i=1;i<=a;i++){
        	s+=b;
		}
}
 for(int i=0;i<len;i++){
 	if(s[i]!=s[0]){
    	break;
	}
	if(i==len-1){
		 cout<<0;
		 return 0;
	}
 }
 long long k=s.size();
     long long mid=k/2;
     cout<<min(gz(mid),gy(mid));
	return 0;
} 
