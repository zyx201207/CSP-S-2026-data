#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long num[n];
    char ch[n];
    for(int i=0;i<n;i++){
        cin >> num[i] >> ch[i];
    }
    long long a=num[0],b=num[n-1],sum=0;
    int i=0,j=n-1;
    while(i<j){
        if(a>b){
            if(ch[i] != ch[j])sum+=b;
            a-=b;
            b=0;
        }else{
            if(ch[i] != ch[j])sum+=a;
            b-=a;
            a=0;
        }
        if(a==0){
            i++;
            a=num[i];
        }
        if(b==0){
            j--;
            b=num[j];
        }
    }
    cout << sum;
    return 0;    
}