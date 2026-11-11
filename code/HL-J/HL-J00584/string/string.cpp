#include<bits/stdc++.h>
using namespace std;
int a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin>>n; 
    char ch;
    for(int i=1;i<=n;i++){
    	cin>>a>>ch;
    	for(int j=1;j<=a;j++){
    		s+=ch;
		}
	}
	int l=0,r=s.size();
	int len=s.size();
    while(l<r){
    	if(s[l]==s[r]){
    		l++;
    		r--;
		}
		else if(s[l]!=s[r]){
			sum++;
			l++;
			r--;
		}
	}
	cout<<sum;
    return 0;
}
