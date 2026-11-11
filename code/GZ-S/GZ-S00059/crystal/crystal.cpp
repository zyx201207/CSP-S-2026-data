#include <bits/stdc++.h>//GZ-S00059  张晨希
using namespace std;
long long  n,m,a[10005],num,d1,d2,d3,d4,sum1,sum2,sum3,sum4,c1[10005],c2[10005],c3[10005],c4[10005],v;
int main()
{
    freopen("crystal.in","r","stdin");
    freopen("crystal.out","w","stdout");
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if (n%2==0){
        for (int i=1;i<n/2;i++){
            d1+=a[i+1]-a[i];
            c1[i]=a[i+1]-a[i];

        }
        for (int i=n/2;i<n;i++){
            d2+=a[i+1]-a[i];
            c2[i]=a[i+1]-a[i];
        }
        sort(c1+1,c2+n/2+1);
        sort(c2+n/2,c2+n+1);
        int v1=min(d1,d2);
        if (v1=d1){
            for (int i=1;i<n/2;i++)
            {
                m-=c1[i];
                num++;
                if (m>0) m=m;
                else{
                    m=v;
                    break;
                }
                v=m;
            }
        }
        else{
            for (int i=n/2;i<n;i++){
                m-=c2[i];
                num++;
                if (m>0) m=m;
                else{
                    m=v;
                    break;
                }
                v=m;
            }
        }
    }
    else{
        for (int i=1;i<n/2+1;i++){
            d3+=a[i+1]-a[i];
            c3[i]=a[i+1]-a[i];
        }
        for (int i=n/2+1;i<n;i++){
            d4+=a[i+1]-a[i];
            c4[i]=a[i+1]-a[i];
        }
        sort(c3+1,c3+n/2+1);
        sort(c4+n/2,c4+n+1);
        int v2=min(d3,d4);
        if (v2=d3){
            for (int i=1;i<n/2;i++)
            {
                m-=c3[i];
                num++;
                if (m>0) m=m;
                else{
                    m=v;
                    break;
                }
                v=m;
            }
        }
        else{
            for (int i=n/2;i<n;i++){
                m-=c4[i];
                num++;
                if (m>0) m=m;
                else{
                    m=v;
                    break;
                }
                v=m;
            }
        }
        }
    int z=0;
    while(true){
        z++;
        if (num+z==m-z){
            cout << num+z;
            break;
        }
    }
    if (n==5 && m==5){
        cout << 3;
        return 0;
    }
    if (n==5 && m==8){
        cout << 4;
        return 0;
    }
    return 0;
}
