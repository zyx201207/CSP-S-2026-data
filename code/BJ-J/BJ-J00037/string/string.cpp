#include<bits/stdc++.h>
using namespace std;
long long l=0ll;
int n,a[200005];
long long ans=0;
char c[200005];
vector<long long> left0,right0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    int lindex=-1,rindex=-1;
    if(l%2==0){
        long long sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(sum>=l/2 && lindex==-1){
                lindex=i;
                left0.push_back(l/2-(sum-a[i]));
            }
            if(sum>l/2){
                rindex=i;
                right0.push_back(sum-l/2);
                break;
            }
        }
    }
    else{
        long long sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(sum>=(l-1)/2 && lindex==-1){
                lindex=i;
                left0.push_back((l-1)/2-(sum-a[i]));
            }
            if(sum>(l+1)/2){
                rindex=i;
                right0.push_back(sum-(l+1)/2);
                break;
            }
        }
    }
    for(int i=lindex-1;i>=1;i--){
        left0.push_back(a[i]);
    }
    for(int i=rindex+1;i<=n;i++){
        right0.push_back(a[i]);
    }
/*
    cout<<"lindex "<<lindex<<" rindex "<<rindex<<endl;

    cout<<"left ";
    for(int i=0;i<=left0.size()-1;i++){
        cout<<left0[i]<<" ";
    }
    cout<<endl;
    cout<<"right ";
    for(int i=0;i<=right0.size()-1;i++){
        cout<<right0[i]<<" ";
    }
    cout<<endl;
*/
    long long li=0,ri=0,lsum=0,rsum=0,p=0,newlsum,newrsum;
    while(!(li>left0.size()-1 && ri>right0.size()-1)){
        //cout<<"li "<<li<<" ri "<<ri<<" lsum "<<lsum<<" rsum "<<rsum<<" p "<<p<<" ans "<<ans<<endl;
        //cout<<"cl "<<c[lindex-li]<<" cr "<<c[rindex+ri]<<endl;
        if(ri>right0.size()-1){
            newlsum=lsum+left0[li];
            if(c[lindex-li]!=c[rindex+ri])ans+=newlsum-p;
            p=lsum=newlsum;
            li++;
        }
        else if(li>left0.size()-1){
            newrsum=rsum+right0[ri];
            if(c[lindex-li]!=c[rindex+ri])ans+=newrsum-p;
            p=lsum=newrsum;
            ri++;
        }
        else{
            newlsum=lsum+left0[li];
            newrsum=rsum+right0[ri];
            if(newlsum==newrsum){
                if(c[lindex-li]!=c[rindex+ri])ans+=newlsum-p;
                p=lsum=rsum=newlsum;
                li++;
                ri++;
            }
            else if(newlsum<newrsum){
                if(c[lindex-li]!=c[rindex+ri])ans+=newlsum-p;
                p=lsum=newlsum;
                li++;
            }
            else if(newlsum>newrsum){
                if(c[lindex-li]!=c[rindex+ri])ans+=newrsum-p;
                p=rsum=newrsum;
                ri++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
