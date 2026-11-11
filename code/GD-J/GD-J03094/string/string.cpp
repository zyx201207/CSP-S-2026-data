#include<bits/stdc++.h>
using namespace std;
int n,a[200005],c[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    	cin>>c[i];
    	s+=a[i]*s[i]; 
	}
    int x=s.length();
	for(int i=1;i<=x;i++){
        if(s[i]!=s[x+1-i]){
        	if(s[i]!=s[i+1]||s[x+1-i]!=s[x-i]){
        		cnt++;
			}
		}
	}
    cout<<s;
    return 0;
    
}
