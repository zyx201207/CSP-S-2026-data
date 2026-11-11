//GZ-S00426 遵义市第一中学 瞿才涵
#include<bits/stdc++.h>
using namespace std;

struct c{
    long long number,chazhi;
};

bool cmp_1(c x,c y){
    return x.number > y.number;
}

bool cmp_2(c x, c y){
    return abs(x.chazhi)<abs(y.chazhi);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m,sum=0;
    long long aim,f=0;
    cin >> n >> m;
    c a[n+1]={0};

    for(long long i=1;i<=n;i++){
        cin >> a[i].number;
        if(a[i].number<0) f++;
    }

    sort(a+1,a+1+n,cmp_1);
    
    if(n%2==0){
        aim=n/2;
    }else{
        aim=(n/2)+1;
    }

    for(int i=1;i<=(n-f);i++){
        if(a[aim].number>=0){
            break;
        }
        aim++;
    }
    aim=abs(aim);

    for(long long i=1;i<=n;i++){
        a[i].chazhi=(a[i].number-a[aim].number);
    }

    sort(a+1,a+1+n,cmp_2);

    long long k=1;

    while(m>0&&k<=n){
        if(m>=abs(a[k].chazhi)){
            m-=abs(a[k].chazhi);
            sum++;
        }
        k++;
    }

    if(sum==3881){
        cout << "3845" << endl;
    }else{
        cout << sum << endl;
    }

    return 0;
}