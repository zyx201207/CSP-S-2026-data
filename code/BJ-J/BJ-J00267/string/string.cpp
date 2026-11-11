#include<bits/stdc++.h>
using namespace std;
struct o{
    long long num;
    char tr;
}a[200010];
int n;
int ans;
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].tr;
        sum+=a[i].num;
    }
    if(sum&1){
        sum/=2;
        sum+=1;
        int in=1;
        while(sum>a[in].num){
            sum-=a[in].num;
            in++;
        }
        for(int i=n;i>=in+1;i--){
            a[i+1].num=a[i].num;
            a[i+1].tr=a[i].tr;
        }
        int t=a[in].num;
        a[in].num=sum-1;
        a[in+1].num=t-sum;
        a[in+1].tr=a[in].tr;
        // start to change
        int l=in,r=in+1;
        int ltn=a[l].num;
        int rtn=a[r].num;
        while(l>=1 && r<=n+1){
            if(ltn>rtn){
                if(a[l].tr==a[r].tr){
                    ltn-=rtn;
                    r++;
                    rtn=a[r].num;
                }else{
                    ans+=rtn;
                    ltn-=rtn;
                    r++;
                    rtn=a[r].num;
                }
            }
            if(ltn<rtn){
                if(a[l].tr==a[r].tr){
                    rtn-=ltn;
                    l--;
                    ltn=a[l].num;
                }else{
                    ans+=ltn;
                    rtn-=ltn;
                    l--;
                    ltn=a[l].num;
                }
            }
            if(ltn==rtn){
                if(a[l].tr==a[r].tr){
                    l--;
                    r++;
                    ltn=a[l].num;
                    rtn=a[r].num;
                }else{
                    ans+=ltn;
                    l--;
                    r++;
                    ltn=a[l].num;
                    rtn=a[r].num;
                }
            }
        }
        cout<<ans;
    }else{
        sum/=2;
        int in=1;
        while(sum>a[in].num){
            sum-=a[in].num;
            in++;
        }

        if(sum!=a[in].num){
            for(int i=n;i>=in+1;i--){
                a[i+1].num=a[i].num;
                a[i+1].tr=a[i].tr;
            }
            int t=a[in].num;
            a[in].num=sum-1;
            a[in+1].num=t-sum-1;
            a[in+1].tr=a[in].tr;
            //cout<<in<<endl;
            int l=in,r=in+1;
            int ltn=a[l].num;
            int rtn=a[r].num;
            //cout<<ltn<<" "<<rtn<<endl;
            while(l>=1 && r<=n+1){
                if(ltn>rtn){
                    if(a[l].tr==a[r].tr){
                        //cout<<"1x"<<l<<" "<<r<<endl;
                        ltn-=rtn;
                        r++;
                        rtn=a[r].num;
                    }else{
                        ans+=rtn;
                        //cout<<"1 "<<l<<" "<<r<<" "<<ans<<endl;
                        ltn-=rtn;
                        r++;
                        rtn=a[r].num;
                    }
                }else if(ltn<rtn){
                    if(a[l].tr==a[r].tr){
                        //cout<<"2x"<<l<<" "<<r<<endl;
                        rtn-=ltn;
                        l--;
                        ltn=a[l].num;
                    }else{
                        ans+=ltn;
                        //cout<<"2 "<<l<<" "<<r<<" "<<ans<<endl;
                        rtn-=ltn;
                        l--;
                        ltn=a[l].num;
                    }
                }else if(ltn==rtn){
                    if(a[l].tr==a[r].tr){
                        //cout<<"3x"<<l<<" "<<r<<endl;
                        l--;
                        r++;
                        ltn=a[l].num;
                        rtn=a[r].num;
                    }else{
                        ans+=ltn;
                        //cout<<"3 "<<l<<" "<<r<<" "<<ans<<endl;
                        l--;
                        r++;
                        ltn=a[l].num;
                        rtn=a[r].num;
                    }
                }
            }
            cout<<ans;
        }else{
            a[in].num-=1;
            a[in+1].num-=1;
            if(a[in].tr!=a[in+1].tr){
                ans++;
            }
            int l=in,r=in+1;
            int ltn=a[l].num;
            int rtn=a[r].num;
            while(l>=1 && r<=n){
                if(ltn>rtn){
                    if(a[l].tr==a[r].tr){
                        ltn-=rtn;
                        r++;
                        rtn=a[r].num;
                    }else{
                        ans+=rtn;
                        ltn-=rtn;
                        r++;
                        rtn=a[r].num;
                    }
                }
                if(ltn<rtn){
                    if(a[l].tr==a[r].tr){
                        rtn-=ltn;
                        l--;
                        ltn=a[l].num;
                    }else{
                        ans+=ltn;
                        rtn-=ltn;
                        l--;
                        ltn=a[l].num;
                    }
                }
                if(ltn==rtn){
                    if(a[l].tr==a[r].tr){
                        l--;
                        r++;
                        ltn=a[l].num;
                        rtn=a[r].num;
                    }else{
                        ans+=ltn;
                        l--;
                        r++;
                        ltn=a[l].num;
                        rtn=a[r].num;
                    }
                }
            }
            cout<<ans;
        }
    }

    return 0;
}
