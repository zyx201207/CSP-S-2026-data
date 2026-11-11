#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    char c;
    int n,a[100005],b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        s[i]=c;
    }
    for(int i=1;i<=n;i++){
		s[i]=s[i]*a[i];
	}
    for(int i=1;i<=n;i++){
    	if(s[i]==s[i+1]){
    		b=0;
		}
	}
	cout<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
