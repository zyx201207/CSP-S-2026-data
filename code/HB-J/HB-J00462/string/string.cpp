#include<bits/stdc++.h>
using namespace std;
unsigned long long n,lenf=0,x,m,sum;
unsigned long long a[200123];
int tim[200123];
int searf(int p)
{
    int l=1,r=n;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]<p){
            l=m+1;
        }
        else if(a[m]>p&&a[m-1]<p||a[m]==p){
            return tim[m];
        }
        else{
            r=m;
        }
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    cin.tie(nullptr);
    char t;
    for(int i=1;i<=n;i++){
        cin>>x;
        cin>>t;
        lenf+=x;
        a[i]=a[i-1]+x;
        tim[i]=t-'a';
    }
    unsigned long long mif=0,maf=n;
    unsigned long long l1,l2;
    for(unsigned long long i=1;i<lenf/2;i++){
        if(i>a[mif]){
            l1=searf(i);
            mif++;
        }
        if(lenf-i+1<=a[maf]){
            l2=searf(lenf-i+1);
            maf--;
        }
        if(l1!=l2){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
