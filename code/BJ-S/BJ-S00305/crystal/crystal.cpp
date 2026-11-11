#include<iostream>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);/////////////////////////////////////////////////
    freopen("crystal.out","w",stdout);///////////////////////////////////////////////
    long long n,m,a1,a2,ch,c,cnt=0;
    cin>>n>>m;
    cin>>a1>>a2;
    ch=max(a2-a1,a1-a2);c=ch;
    while(m>=0){
        m-=c;
        cnt++;
        //cout<<"tianping di "<<cnt<<" ge quekou, yongle "<<c<<" ci jihui, haisheng "<<m<<"ci\n";
        c+=ch;
    }
    cout<<cnt;
    return 0;
}/*#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long a1[500005];
int main(){
    //freopen("crystal.in","r",stdin);/////////////////////////////////////////////////
    //freopen("crystal.out","w",stdout);///////////////////////////////////////////////
    long long n,m;long long Min=0,mxzs=0;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"X1";////////////////////////////////////////////////////////////////////////
    sort(a+1,a+n);
    {long long zs=-1;
    for(long long i=0;i<n;i++){
        if(i){
            a1[i]=a[i]-a[i-1];
            if(abs(a1[Min])>abs(a1[i]))Min=i;
        }
        if(a[i]==a[i+1]){
            zs++;
        }else{
            if(zs>a[mxzs]){
                mxzs=i;
            }zs=0;
        }
    }}
    cout<<"X2";////////////////////////////////////////////////////////////////////////
    a[Min]-=a1[Min];
    m+=a1[Min];
    long long mn,l=Min,r=Min,lr;
    if(a1[l-1]<a1[r+1])
    {mn=l-1;l--;lr='l';}
    else
    {mn=r+1;r++;lr='r';}
    while(m>0){
        a[mn]-=a1[mn];
        m+=a1[mn];
        if(a1[l-1]<a1[r+1]){mn=l-1;l--;lr='l';}
        else{mn=r+1;r++;lr='r';}
    }
    cout<<"X1";////////////////////////////////////////////////////////////////////////
    cout<<r-l;
    return 0;
}//*/
/*gaichengzhege 5 5 121 2 3 4 5 guole 5 5 1 2 3 4 5 meiguo yangliyi meiguo
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long a1[500005];
int main(){
    //freopen("crystal.in","r",stdin);/////////////////////////////////////////////////
    //freopen("crystal.out","w",stdout);///////////////////////////////////////////////
    long long n,m;long long Min=0;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"X1";////////////////////////////////////////////////////////////////////////
    sort(a+1,a+n);
    {long long zs=-1;
    for(long long i=0;i<n;i++){
        if(i){
            a1[i]=a[i]-a[i-1];
            if(abs(a1[Min])>abs(a1[i]))Min=i;
        }
    }}
    cout<<"X2";////////////////////////////////////////////////////////////////////////
    a[Min]-=a1[Min];
    m+=a1[Min];
    long long mn,l=Min,r=Min,lr;
    if(a1[l-1]<a1[r+1])
    {mn=l-1;l--;lr='l';}
    else
    {mn=r+1;r++;lr='r';}
    while(m>0){
        a[mn]-=a1[mn];
        m+=a1[mn];
        if(a1[l-1]<a1[r+1]){mn=l-1;l--;lr='l';}
        else{mn=r+1;r++;lr='r';}
    }
    cout<<"X1";////////////////////////////////////////////////////////////////////////
    cout<<r-l;
    return 0;
}//*/


