#include<bits/stdc++.h>
using namespace std;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int s[n];
    char ss[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        cin>>ss[i];
    }
    int leftt=0,rightt=n-1,lef=1,righ=1;
    while(){
	if(lef>s[leftt]){
	    lef=1;
            leftt++;
        }
        if(righ>s[rightt]){
            righ=1;
            rightt--;
        }
        if(ss[leftt]!=ss[rightt]){
            ans++;
        }
        if(n%2==1){
            if(leftt==rightt and lef==s[leftt]-righ+1){
                break;
            }
        }
        else{
            if(leftt==rightt and lef==s[leftt]-righ){
                break;
            }
            else if(leftt==rightt-1 and s[leftt]-lef==0 and s[rightt]-righ==0){
                break;
            }
        }
        lef++;
        righ++;
    }
    cout<<ans;
    return 0;
}
