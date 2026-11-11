#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[100005],t;
char c[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
	        s+=c[i];
	    }
    }
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j]){
        	s[j]=s[i];
        	t++;
		}
    }
	cout<<t;

    return 0;
}
