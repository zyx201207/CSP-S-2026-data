#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,tu,we;
struct hui{
    long long l;
    char z;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    hui s[200010];
    cin>>n;
    tu=0;we=n-1;
    for(int i=0;i<n;i++){
        cin>>s[i].l>>s[i].z;
    }
    while(tu!=we){
        if(s[tu].z==s[we].z)
        {
            if(s[tu].l>s[we].l)
            {
                s[tu].l-=s[we].l;
                we--;
            }else{
                if(s[tu].l<s[we].l)
                {
                    s[we].l-=s[tu].l;
                    tu++;
                }else{
                    tu++;
                    we++;
                }
            }
        }else{
            if(s[tu].l>s[we].l)
            {
                s[tu].l-=s[we].l;
                m+=s[we].l;
                we--;
            }else{
                m+=s[tu].l;
                if(s[tu].l<s[we].l)
                {
                    s[we].l-=s[tu].l;
                    tu++;
                }else{
                    tu++;
                    we++;
                }
            }
        }
    }
    cout<<m;
    return 0;
}
