#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long ans;
struct _{
    int s;
    char c;
}a[200005];
bool check(int x){
    if(x%2==0){
        x=x/2;
        for(int i=1;i<=x;i++){
            for(int j=n;j>=x+1;j--){
                if(a[i].c!=a[j].c||a[i].s!=a[j].s){
                    return 0;
                    break;
                }
            }
        }
        return 1;
    }
    else{
        x=x/2+1;
        for(int i=1;i<x;i++){
            for(int j=n;j>x;j--){
                if(a[i].c!=a[j].c||a[i].s!=a[j].s){
                    return 0;
                    break;
                }
            }
        }
        return 1;
    }
}
void sum(int x){
    if(x%2==0){
        x=x/2;
        for(int i=1;i<=x;i++){
            for(int j=n;j>=x+1;j--){
                if(a[i].s==0||a[j].s==0){
                    continue;
                }
                if(a[i].c!=a[j].c){
                    if(a[i].s==a[j].s){
                        ans+=a[i].s;
                    }
                    else{
                        if(a[i].s<a[j].s){
                            ans+=a[j].s;
                            a[i].c=a[j].c;
                            a[i].s=a[j].s;
                            a[i+1].s=a[i+1].s-(a[j].s-a[i].s);
                            ans=ans+(a[j].s-a[i].s);
                        }
                        if(a[i].s>a[j].s){
                            ans+=a[i].s;
                            a[j].c=a[i].c;
                            a[j].s=a[i].s;
                            a[j-1].s=a[j-1].s-(a[i].s-a[j].s);
                            ans=ans+a[i].s-a[j].s;
                        }
                    }
                }
                else if(a[i].s!=a[j].s){
                    if(a[i].s>a[j].s){
                        a[j].s=a[i].s;
                        a[j-1].s=a[j-1].s-(a[i].s-a[j].s);
                        ans=ans+a[i].s-a[j].s;
                    }
                    else{
                        a[i].s=a[j].s;
                        a[i+1].s=a[i+1].s-(a[j].s-a[i].s);
                        ans=ans+(a[j].s-a[i].s);
                    }
                }
            }
        }
    }
    else{
        x=x/2+1;
        for(int i=1;i<x;i++){
            for(int j=n;j>x;j--){
                if(a[i].s==0||a[j].s==0){
                    continue;
                }
                if(a[i].c!=a[j].c){
                    if(a[i].s==a[j].s){
                        ans+=a[i].s;
                    }
                    else{
                        if(a[i].s<a[j].s){
                            ans+=a[j].s;
                            a[i].c=a[j].c;
                            a[i].s=a[j].s;
                            a[i+1].s=a[i+1].s-(a[j].s-a[i].s);
                            ans=ans+(a[j].s-a[i].s);
                        }
                        if(a[i].s>a[j].s){
                            ans+=a[i].s;
                            a[j].c=a[i].c;
                            a[j].s=a[i].s;
                            a[j-1].s=a[j-1].s-(a[i].s-a[j].s);
                            ans=ans+a[i].s-a[j].s;
                        }
                    }
                }
                else if(a[i].s!=a[j].s){
                    if(a[i].s>a[j].s){
                        a[j].s=a[i].s;
                        a[j-1].s=a[j-1].s-(a[i].s-a[j].s);
                        ans=ans+a[i].s-a[j].s;
                    }
                    else{
                        a[i].s=a[j].s;
                        a[i+1].s=a[i+1].s-(a[j].s-a[i].s);
                        ans=ans+(a[j].s-a[i].s);
                    }
                }
            }
        }
    }
    cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    bool t1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].c;
        if(a[i].c!=a[i-1].c){
            t1=0;
        }
    }
    if(t1==1){
        cout<<0;
        return 0;
    }
    else if(check(n)==1){
        cout<<0;
        return 0;
    }
    else{
        sum(n);
    }
    return 0;
}