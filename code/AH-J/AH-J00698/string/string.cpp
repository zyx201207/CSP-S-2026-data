#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m,c=1,y,cnt=0;
    char x;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>x;
        for(int j=c;j<c+m;j++){
            s[j]=x;
        }
        c+=m;
    }
    y=c-1;
    for(int j=1;j<c;j++){
        if(s[j]!=s[y]){
            cnt++;
        }
        y--;
    }
    cout<<cnt/2;
	return 0;
}
