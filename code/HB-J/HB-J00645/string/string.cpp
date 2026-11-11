#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=int(1e5)*2+5;
struct subString{
    int cnt;
    char c;
}subStrs[MAXN];
int n;
ll cdLen(ll l1,ll r1,ll l2,ll r2){
    // cout<<max(l1,l2)<<' '<<min(r1,r2)<<endl;
    return max(min(r1,r2)-max(l1,l2),(ll)0);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll sumLen=0;
    for(int i=1;i<=n;i++){
        cin>>subStrs[i].cnt>>subStrs[i].c;
        sumLen+=subStrs[i].cnt;
    }
    ll ans=0;
    ll lSum=0,rSum=0,r_=n+1;
    // cout<<(LONG_LONG_MAX)<<endl;
    for(int i=1;i<=n;i++){
        lSum+=subStrs[i].cnt;
        int f=0;
        if(lSum>=sumLen/2){
            f=1;
            // lSum=sumLen/2;
        }
        // cout<<__LINE__<<' '<<lSum<<' '<<rSum<<endl;
        // if(lSum<=rSum){
        //     cout<<"lSum<=rSum"<<endl;
        // }
        if(lSum<=rSum&&subStrs[r_].c!=subStrs[i].c){
            ans+=cdLen(lSum-subStrs[i].cnt,lSum,(rSum-subStrs[r_].cnt),rSum);
            // cout<<__LINE__<<' '<<lSum-subStrs[i].cnt<<' '<<lSum<<' '<<rSum-subStrs[r_].cnt<<' '<<rSum<<endl;
            // cout<<"ans+="<<cdLen(lSum-subStrs[i].cnt,lSum,(rSum-subStrs[r_].cnt),rSum)<<" i="<<i<<" r_="<<r_<<" ans="<<ans<<endl;
            // cout<<"cdLen("<<lSum-subStrs[i].cnt<<','<<lSum<<','<<rSum-subStrs[r_].cnt<<','<<rSum<<")"<<endl;
        }
        else if(lSum-subStrs[i].cnt<rSum&&lSum>rSum&&subStrs[r_].c!=subStrs[i].c){
            ans+=cdLen(lSum-subStrs[i].cnt,lSum,(rSum-subStrs[r_].cnt),rSum);
            // cout<<__LINE__<<' '<<lSum-subStrs[i].cnt<<' '<<lSum<<' '<<rSum-subStrs[r_].cnt<<' '<<rSum<<endl;
            // cout<<"ans+="<<cdLen(lSum-subStrs[i].cnt,lSum,(rSum-subStrs[r_].cnt),rSum)<<" i="<<i<<" r_="<<r_<<" ans="<<ans<<endl;
            // cout<<"cdLen("<<lSum-subStrs[i].cnt<<','<<lSum<<','<<rSum-subStrs[r_].cnt<<','<<rSum<<")"<<endl;
        }
        while(rSum<lSum){
            rSum+=subStrs[--r_].cnt;
            if(subStrs[r_].c!=subStrs[i].c){
                ans+=cdLen(lSum-subStrs[i].cnt,lSum,(rSum-subStrs[r_].cnt),rSum);
                // cout<<__LINE__<<' '<<lSum-subStrs[i].cnt<<' '<<lSum<<' '<<rSum-subStrs[r_].cnt<<' '<<rSum<<endl;
                // cout<<"ans+="<<cdLen(lSum-subStrs[i].cnt,lSum,(rSum-subStrs[r_].cnt),rSum)<<" i="<<i<<" r_="<<r_<<endl;
                // cout<<"cdLen("<<lSum-subStrs[i].cnt<<','<<lSum<<','<<rSum-subStrs[r_].cnt<<','<<rSum<<")"<<endl;
                // if(rSum>lSum||1){
                //     // ans+=subStrs[l_].cnt;
                // }
                // else{
                //     ans+=subStrs[r_].cnt;
                //     // cout<<__LINE__<<"ans+="<<subStrs[r_].cnt<<endl;
                // }
            }
        }
        // cout<<"lsum="<<lSum<<" rsum="<<rSum<<" ans="<<ans<<endl;
        if(f||lSum+rSum==sumLen){
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
    // // for(int i=1;i<=n;i++){
    // //     cout<<get_(i)<<' ';
    // // }
    // cout<<endl;
    
    // // ll ans=0;
    
    // if(sumLen%2==0||1){
    //     cout<<"***"<<endl;
    //     // int sl=0;
    //     // for(int i=1;i<=n;i++){
    //     //     sl+=subStrs[i].cnt;
    //     //     if(sl>=sumLen/2){
    //     //         break;
    //     //     }
    //     // }
    //     ll lsum=subStrs[1].cnt,rsum=subStrs[n].cnt;
    //     int l_=1,r_=n;
    //     while((lsum+rsum)<=sumLen){
    //         if(lsum<rsum){
    //             if(subStrs[l_].c!=subStrs[r_].c){
    //                 ans+=subStrs[l_].cnt-rsum;
    //                 cout<<"ans+ l "<<l_<<' '<<rsum<<endl;
    //             }
    //             lsum+=subStrs[++l_].cnt;
    //         }
    //         else{
    //             if(subStrs[l_].c!=subStrs[r_].c){
    //                 ans+=subStrs[r_].cnt-lsum;
    //                 cout<<"ans+ r "<<r_<<' '<<lsum<<endl;
    //             }
    //             rsum+=subStrs[--r_].cnt;
    //         }
    //     }
    //     // for(int i=1;i<=n;i++){
    //     //     if(l<r){

    //     //     }
    //     //     if((l+r)>sumLen){
    //     //         break;
    //     //     }
    //     // }
    // }
    // cout<<ans;
    return 0;
}

/*
3
2 a
2 b
1 c

2
*/

/*
2
2 a
3 a

0
*/

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000
*/

/*
6
1 a
1 c
2 a
1 b
2 c
1 d

3
*/

/*
6
2 a
2 d
1 f
1 d
2 c
1 b
*/