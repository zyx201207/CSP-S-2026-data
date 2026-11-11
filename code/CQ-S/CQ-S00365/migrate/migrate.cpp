/***************
 - @GavinCQTD
***************/

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

ifstream fin("migrate.in");
ofstream fout("migrate.out");

int c,t,n,pre[2000005],nxt[2000005],dist[305][305],f[305][305][305],sumf[305][305][305];
ll d,x[2000005];

void solve(int tid){
    fin >> n >> d;
    for(int i=1;i<=n;i++){
        fin >> x[i];
    }
    
    if(n<=3){
        fout << "0\n";
        return;
    }
    
    for(int i=1;i<=n;i++){
        int l=i+1,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(x[mid]-x[i]<=d){
                nxt[i] = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        l = 1;
        r = i-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(x[i]-x[mid]<=d){
                pre[i] = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        nxt[i] = (nxt[i]==0?n:nxt[i]);
        pre[i] = (pre[i]==0?1:pre[i]);
//        cerr << i << " " << pre[i] << " " << nxt[i] << "\n";
    }
    
    for(int i=1;i<=n;i++){
        int p=i,dis=0;
        while(p!=n){
            dis++;
            for(int j=p+1;j<=nxt[p];j++){
                dist[i][j] = dis;
            }
            p = nxt[p];
        }
    }

    ll fans=0;
    for(int i=1;i<=n;i++){
        f[i][i][0] = sumf[i][i][0] = 1;
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[j-1]>d){
                break;
            }
            for(int k=dist[i][j];k<=j-i;k++){
//                for(int lst=pre[j];lst<j;lst++){
//                    f[i][j][k] += f[i][lst][k-1];
//                }
                f[i][j][k] += sumf[i][j-1][k-1]-sumf[i][pre[j]-1][k-1];
            }
            for(int k=0;k<=j-i;k++){
                sumf[i][j][k] = sumf[i][j-1][k]+f[i][j][k];
            }
            fans += (f[i][j][dist[i][j]]==2);
        }
    }
    fout << fans << "\n";

    memset(f,0,sizeof f);
    memset(dist,0,sizeof dist);
    memset(pre,0,sizeof pre);
    memset(nxt,0,sizeof nxt);
    memset(sumf,0,sizeof sumf);
}

int main(){
    fin >> c >> t;
    
    for(int i=1;i<=t;i++){
        solve(i);
//        cerr << "------\n";
    }
    
    return 0;
}

/*
�ܹ����˫���Ե���С�ṹ
x1 x2 x3 x4
x3 - x1 <= d
x4 - x1 > d
ֻҪ·���ϳ�������ṹǡ��һ�ξ��ǿ��Ե�
444444444444444442 444444444444444442 222222222222222221 222222222222222221 222222222222222221 444444444444444442
666666666666666663
*/

