#include<bits/stdc++.h>
using namespace std;
long long n,ans,s;
string S;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		ans+=a;
		for(int i=1;i<=a;i++){
		    S+=c;	
	    }
    }
    long long l=0,r=ans-1;
    while(l!=r){
		if(S[l]!=S[r])s++;
		l++;r--;
	}
	cout<<s;
	return 0;
}
