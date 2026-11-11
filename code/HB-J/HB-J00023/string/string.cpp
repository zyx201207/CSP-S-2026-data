#include <bits/stdc++.h>
using namespace std;
long long n=0;
long long sum=0;
long long t=0;
char d='0';
string a[9999999];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sum>>d;

        for(int i=t;i<t+sum;i++){
            a[i]=d;
        }
        t=t+sum;
        d='0';
        sum=0;
    }
    long long i=0;
    long long j=t-1;
    long long cut=0;
    while(i<j){
        if(a[i]==a[j]){

            i++;
            j--;
        }
        else{
            cut++;
            i++;
            j--;
        }
    }
    cout<<cut;

    return 0;

}
