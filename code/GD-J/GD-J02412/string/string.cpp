#include<bits/stdc++.h>
using namespace std;
int n,ans,x,cnt=1,z;
char y;
vector<char>s(1000000000,' ');
vector<char>a1(1000000000,' ');
vector<char>a2(1000000000,' ');
int main(){
    freopen("string.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        for(int j=0;j<x;j++){
            s[cnt]=y;
            cnt++;
		}
    }
    cnt--;
    // for(int i=1;i<=cnt;i++){
    // 	cout<<s[i];
	// } 
    for(int i=1;i<=cnt>>1;i++){
        a1[i]=s[i];
    }
    z=cnt/2;
    if(cnt%2!=0) z++;
    for(int i=1;i<=z;i++){
        a2[i]=s[i+z];
    }
    for(int i=1;i<=cnt/2;i++){
        if(a1[i]!=a2[i]){
            ans++;
        }
    }
    freopen("string.out","w",stdout);
    // cout<<cnt<<'\n';
    // for(int i=1;i<=cnt/2;i++){
    //     cout<<a1[i];
    // }
    // cout<<'\n';
    // for(int i=1;i<=cnt/2;i++){
    //     cout<<a2[i];
    // }
    cout<<ans;
}
