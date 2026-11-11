//GZ-J00055 李汭曦
#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,sun=1,sum=0;cin>>n;
    for(int i=1;i<=n;i++){
        int s;cin>>s;char ss;cin>>ss;
        for(int j=1;j<=s;j++){
            a[sun]+=ss;
            sun++;
        }
    }
    int l=1,r=sun-1,cnt=0;
    while(l<=r){
        if(a[l]!=a[r]){
            cnt++;
        }
        l++;r--;
    }
    cout<<cnt;
	return 0;
}

