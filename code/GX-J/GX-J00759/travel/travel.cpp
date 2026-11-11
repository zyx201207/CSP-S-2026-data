#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);

    string a;
    for(int i=0;i<=11;i++){
        cin>>a[i];
    }
    int m=0;
    int n=0;
    int h=0;
    int p=0;
    for (int i=0;i<=1;i++){
        if(a[i]==a[i+7]){
            m++;
        }

    }
    for (int j=3;j<=1;j++){
        if(a[j]==a[j+7]){
            n++;
        }
    }
    if (a[5]=='A'|| a[12]=='A'){
        h++;
    }
    if (a[5]=='B'|| a[12]=='B'){
        h++;
    }
    if (a[5]=='C'|| a[12]=='C'){
        h++;
    }

    if (a[5]=='B' && a[12]=='C'){
        p++;
    }
    if (a[5]=='C' && a[12]=='B'){
        p++;
    }
    if (a[5]=='A' && a[12]=='B'){
        p++;
    }
    if (a[5]=='B' && a[12]=='A'){
        p++;
    }

    if (a[5]=='E' && a[12]=='F'){
        p++;
    }
    if (a[5]=='F' && a[12]=='E'){
        p++;
    }

    if (m==2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if (n==2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(h==2 || h==0){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(p==1){
        cout<<1;
    }
    else{
        cout<<0;
    }

    return 0;
}
