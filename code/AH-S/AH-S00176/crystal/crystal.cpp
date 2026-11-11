#include<bits/stdc++.h>
using namespace std;
long long flagg,n,m,a[500006],cha[500006],q[500006],s[500006],sq[500006],reans[500006],flag;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) flagg=1;
        cha[i]=a[i]-a[i-1];
        cha[1]=0;
        s[i]+=cha[i]+s[i-1];
        memset(sq,0,sizeof sq);
        memset(q,0,sizeof q);
        for(long long j=1;j<i;j++){
            q[j]=s[i]-s[j];
            sq[j]+=q[j]+sq[j-1];
        }
        /*for(int z=0;z<=n;z++){
            cout<<sq[z]<<" ";
        }
        cout<<endl;*/
        flag=0;
        long long l=1,r=i-1,mid=0,re_s=0;//bi
        while(l<r){
            mid=(l+r)/2;
            re_s=sq[i-1]-sq[mid-1];
            if(re_s<m){
                r=mid-1;
            }
            else if(re_s>m){
                l=mid+1;
            }
            else{
                reans[i]=i-mid+1;flag=1;break;
            }
        }
        if(flag==0){
            if(re_s>m) mid++;
            if(re_s<m&&sq[i-1]-sq[mid-2]<=m&&mid>1) mid--;
            //cout<<mid<<endl;
            reans[i]=i-mid+1;
        }
    }
    if(flagg==0){
        for(int i=1;i<=n;i++){
            if(i*(i+1)/2>m){
                cout<<i-1;return 0;
            }
        }
        cout<<n;return 0;
    }
    sort(reans+1,reans+n+1);
    cout<<reans[n];
    return 0;
}
