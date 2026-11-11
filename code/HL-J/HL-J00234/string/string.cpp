#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=1e6+10;
struct Node{
    int num;
    char c;
}p[N];
int shu[N];
string k[N];
string s="";
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int len=0;
    for(int i=1;i<=n;i++){
        int sh;
        char a;
        cin >> sh;
        shu[i]=sh;
        len+=sh;
        cin >> a;
        k[i]=a;
        p[i].num=sh;
        p[i].c=a;
    }
    bool flg=0;
    for(int i=1;i<=n;i++){
        if(p[i].c!=p[i+1].c){
            flg=1;
        }
    }
    if(flg==0){
        cout << 0;
        return 0;
    }
    if(/*len<50000000*/0){
        for(int i=1;i<=n;i++){
            while(shu[i]--){
                s.append(k[i]);
            }
        }
        int sum=0;
        for(int i=0;i<(len/2);i++){
            if(s[i]!=s[len-1-i]){
                sum++;
            }
        }
        cout << sum;

    }else{
        int sum=0;
        //liang ge zhi zhen yong yi geng xin dang qian shou wei.
        int st=0,ed=len-1;
        int idx_st=1;
        int idx_ed=n;
        int mid=len/2;//cong 0 kaishi
       // cout << len << ' '<<mid << endl;
        while(st<mid && ed>mid && idx_st<=n && idx_ed>=1){
            char c1=p[idx_st].c;
            char c2=p[idx_ed].c;
            int n1=p[idx_st].num;
            int n2=p[idx_ed].num;
           // cout << c1 << ' '<<c2 <<  ' '<<  n1 <<' '<< n2 << endl;
            //cout << "idxst:" << idx_st << "  " << "idxed:" << idx_ed << endl;
            //cout << "st:" << st << "  " << "ed:" << ed;
            if(p[idx_st].c!=p[idx_ed].c){
                int minn=min(n1,n2);
                int x;
//                if(idx_ed-minn<mid){
//                    x=mid-(ed-minn+1);
//                    minn=minn-2*x;
//                }
//                if(idx_ed-minn<=mid){
//                    minn=abs(idx_ed-mid);
//                }else if(idx_st+minn>=mid){
//                    minn=abs(mid-idx_st);
//                }
                sum+=minn;
                //cout <<"sum:" << sum<< "minn:" << minn<<endl;
                n1-=minn;
                n2-=minn;
                st+=minn;
                ed-=minn;
               // cout << "n1:" << n1 << "   " << n2 << n2 << endl;
                if(idx_st>=idx_ed || p[idx_st].c==p[idx_ed].c){
                    break;
                }
                if(n1==0){
                    idx_st++;
                }if(n2==0){
                    idx_ed--;
                }else if(n1!=0){
                    p[idx_st].num=n1;
                }else if(n2!=0){
                    p[idx_ed].num=n2;
                }

            }

        }
        cout << sum-2;
    }
    //4
    //8 a
    //3 b
    //3 e
    //10 d
    //len==24   mid==12
    return 0;
}
