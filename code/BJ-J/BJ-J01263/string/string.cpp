#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int sum,len[N],n,l,r,indx,ans,lnum,rnum,lsum,rsum , cnt;
char c[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[++indx]>>c[indx];
        sum += len[indx];
        if(c[indx] == c[indx]-1)
            len[indx-1] += len[indx] , indx--;
    }
    int mid = sum/2;
    for(int i=1;i<=indx;i++){
        cnt += len[i];
        if(sum % 2 == 1){
            if(cnt > mid+1){
                int nlen = cnt-mid-1;
                len[i] = mid-cnt+len[i];
                for(int j=indx;j>i;j--)
                    c[j+1] = c[j] , len[j+1] = len[j];
                len[i+1] = nlen , c[i+1] = c[i];
                indx++;
                break;
           }
           if(cnt == mid+1){
                len[i]--;
                break;
           }
           if(cnt == mid){
                len[i+1]--;
                break;
           }
        }
        else{
            if(cnt == mid)
                break;
            if(cnt > mid){
                int nlen = cnt-mid;
                len[i] = mid-cnt+len[i];
                for(int j=indx;j>i;j--)
                    c[j+1] = c[j] , len[j+1] = len[j];
                len[i+1] = nlen , c[i+1] = c[i];
                indx++;
                break;
            }
        }
    }
    l = 1,r = indx,ans = 0,lnum = len[1],rnum = len[r],lsum = 0,rsum = 0;
    while(lsum<mid && rsum < mid){
        if(c[l] != c[r]){
            if(lnum < rnum){
                ans += rnum - lnum;
                lsum += lnum , rsum += lnum;
                rnum -= lnum  , lnum = len[++l] ;
            }
            else if(rnum < lnum){
                ans += lnum - rnum;
                lsum += rnum , rsum += rnum;
                lnum -= rnum  , rnum = len[--r] ;
            }
            else if(lnum == rnum){
                ans += lnum , rsum += rnum , lsum += lnum , lnum = len[++l] , rnum = len[--r];
            }

        }
        else{
            if(rnum > lnum)
                rsum += lnum , lsum += lnum , lnum = len[++l] , rnum -=  lnum;
            if(lnum > rnum)
                lsum += rnum , rsum += rnum , rnum = len[--r] , lnum -=  rnum;
            if(lnum == rnum)
                lsum += lnum , rsum += rnum , rnum = len[--r] , lnum = len[++l];
        }
    }
    cout<<ans;
    return 0;
}
