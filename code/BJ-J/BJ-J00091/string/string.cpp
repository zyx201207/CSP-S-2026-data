#include<iostream>
#include<string.h>
#include<cstdio>
#define clientaa
int letter[300000];
int s[300000];
char zm[300000];
using namespace std;
int n;
char fnd(int ind){
    int lt=0,rt=n;
    int mid=(lt+rt)>>1;
    while(true){
        if(s[mid]<=ind&&s[mid+1]>ind){
            return zm[mid];
        }
        else{
            if(s[mid]>ind)mid=lt;
            if(s[mid+1]<=ind)mid=rt;
        }
    }
}
int main(){
    #ifndef clientaaa
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    #endif
    cin>>n;
    int sum=0;
    int change=0;
    for(int i=0;i<n;i++){
        cin>>letter[i]>>zm[i];
        if(i==0)s[i]=letter[0];
        else s[i]=letter[i]+s[i-1];
        sum+=letter[i];
    }
    sum--;
    for(int i=0;i<sum/2;i++){
        if(fnd(i)!=fnd(sum-i)){
            change++;
        }

    }
    cout<<change;
    return 0;

}
