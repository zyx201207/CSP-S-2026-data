#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string6.in","r",stdin);
    freopen("string.out","w",stdout);
    long long int n;
    cin>>n;
    long long int ai,sum=0;
    char bi,p='0';
    vector<long long int> a,c;
    vector<char> b,d;
    cin>>ai>>bi;
    sum+=ai;
    p=bi;
    for(long long int i=1;i<n;i++){
        cin>>ai;
        cin>>bi;
        if(p==bi){
            sum+=ai;
        }
        else{
            a.push_back(sum);
            b.push_back(p);
            c.push_back(sum);
            d.push_back(p);
            p=bi;
            sum=ai;
        }
    }
    a.push_back(sum);
    b.push_back(p);
    c.push_back(sum);
    d.push_back(p);
    if(a.size()==1){
        cout<<0;
        return 0;
    }
    reverse(c.begin(),c.end());
    reverse(d.begin(),d.end());
    if(a.size()==2){
        cout<<max(a[0],c[0]);
        return(0);
    }
    long long int num=0;
    sum=0;
    bool cnt=true;
    for(long long int i=0;i<a.size();i++){
        if(!cnt){
            a[i]-=num;
        }
        else{
            c[i]-=num;
        }

        num=abs(a[i]-c[i]);
        if(a[i]>=c[i]){
            cnt=true;
            if(b[i]!=d[i]){
                sum+=c[i];
            }
        }
        else{
            cnt=false;
            if(b[i]!=d[i]){
                sum+=a[i];
            }
        }
    }
    cout<<sum;
    return(0);
}