#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	#define int long long
	int n,o=0,b,l=0,t=0;
	string s,s1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		cin>>s1;
		for(int j=1;j<=b;j++){
			s+=s1;
		}
    }
    if(n%2==0) t=0;
    else t=1;
	for(int i=1;i<=n/2;i++){
		bool f=1;
		for(int j=n;j>=n/2+1+t;j--){
			if(f==1){
				if(s[i-1]==s[j-l-1]){
					l++;
					f=0;
				} 
				else { 
					o++;
					l++;
					f=0;
				}
			}
			else break;	
		}
	}
	cout<<o;
	return 0;
}
