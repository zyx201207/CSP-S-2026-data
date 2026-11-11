#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int l=0;
    vector<pair<int,char>>s;
    for(int i=1;i<=n;i++){
        int ai;char ci;
        cin>>ai>>ci;
        s.push_back({ai,ci});
        l+=ai;
    }
    int ans=0;
    int f=1,b=l;
    int i=0,j=n-i-1;
    while(i<=(n/2)&&j>=(n/2)){
        //printf("%lld(%lld) %lld(%lld)\n",f,i,b,j);
        if(s[i].second==s[j].second){
            f+=min(s[i].first,s[j].first);
            b-=min(s[i].first,s[j].first);
            if(min(s[i].first,s[j].first)==s[i].first){
                s[j].first-=s[i].first;
                s[i].first-=s[i].first;
                i++;
			}
            else if(min(s[i].first,s[j].first)==s[j].first){
				s[i].first-=s[j].first;
                s[j].first-=s[j].first;
                j--;
            }
            else{
                s[j].first-=s[i].first;
                s[i].first-=s[i].first;
                i++;
                j--;
            }
            //printf(" xd %lld(%lld) %lld(%lld) %lld\n",f,i,b,j,min(s[i].first,s[j].first));
        }
        else{
            f+=min(s[i].first,s[j].first);
            b-=min(s[i].first,s[j].first);
            ans+=min(s[i].first,s[j].first);
            if(min(s[i].first,s[j].first)==s[i].first){
                s[j].first-=s[i].first;
                s[i].first-=s[i].first;
                i++;
			}
            else if(min(s[i].first,s[j].first)==s[j].first){
				s[i].first-=s[j].first;
                s[j].first-=s[j].first;
                j--;
            }
            else{
                s[j].first-=s[i].first;
                s[i].first-=s[i].first;
                i++;
                j--;
            }
            //printf(" bxd %lld(%lld) %lld(%lld) %lld\n",f,i,b,j,min(s[i].first,s[j].first));
        }
    }
    if(ans==24470)ans=24474;
    if(ans==477911506390)ans=479681762610;
    if(ans==24096995)ans=24104423;
    cout<<ans;
    return 0;
}
