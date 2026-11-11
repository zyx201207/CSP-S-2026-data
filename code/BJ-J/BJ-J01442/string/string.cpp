#include<bits/stdc++.h>
using namespace std;
struct aabb{
    int nu;
    char el;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].nu>>s[i].el;
        a+=s[i].nu;
    }
    long long cnt=0;
    for(int i=0,j=n-1;i<j;){
        if(s[i].el==s[j].el){
            if(s[i].nu>s[j].nu){
                s[i].nu-=s[j].nu;
                s[j].nu=0;
                j--;
            }else if(s[i].nu==s[j].nu){
                s[j].nu=0;
                s[i].nu=0;
                i++;j--;
            }else{
                s[j].nu-=s[j].nu;
                s[i].nu=0;
                i++;
            }
        }else{
            if(s[i].nu>s[j].nu){
                s[i].nu-=s[j].nu;
                cnt+=s[j].nu;
                s[j].nu=0;
                j--;
            }else if(s[i].nu==s[j].nu){
                cnt+=s[j].nu;
                s[j].nu=0;
                s[i].nu=0;
                i++;j--;
            }else{
                s[j].nu-=s[j].nu;
                cnt+=s[i].nu;
                s[i].nu=0;
                i++;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
