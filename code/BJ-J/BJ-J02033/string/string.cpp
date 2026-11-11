#include <bits/stdc++.h>

using namespace std;
struct node{
    long long n;
    char c;
};
long long n,a;
char ch;
node str1[200015];
node str2[200015];
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long mid=0;
    for(int i=1;i<=n;i++){
        cin>>a>>ch;
        str1[i].n=a;
        str1[i].c=ch;
        str2[n-i+1].n=a;
        str2[n-i+1].c=ch;
        mid+=a;
    }
    mid=mid/2;
    int top=1;
    long long sumtop=str1[top].n;
    int bottom=1;
    long long sumbottom=str2[bottom].n;
    long long sum=0;
    while(sumtop<=mid||sumbottom<=mid){
        long long maxx=max(sumtop,sumbottom);
        long long minn=min(sumtop,sumbottom);
        if(str1[top].c!=str2[bottom].c){
            ans+=minn-sum;                     //判断被包含的
            sum+=minn-sum;
            if(sumtop<sumbottom){
                top++;
                sumtop+=str1[top].n;
            }
            else if(sumtop>sumbottom){
                bottom++;
                sumbottom+=str2[bottom].n;
            }
            else if(sumtop==sumbottom){
                top++;
                sumtop+=str1[top].n;
                bottom++;
                sumbottom+=str2[bottom].n;
            }
        }
        else if(str1[top].c==str2[bottom].c){
            sum+=minn-sum;
            if(sumtop<sumbottom){
                top++;
                sumtop+=str1[top].n;
            }
            else if(sumtop>sumbottom){
                bottom++;
                sumbottom+=str2[bottom].n;
            }
            else if(sumtop==sumbottom){
                top++;
                sumtop+=str1[top].n;
                bottom++;
                sumbottom+=str2[bottom].n;
            }
        }
    }
    long long minn=min(sumtop,sumbottom);
    if(str1[top].c!=str2[bottom].c){
        ans+=max(minn,mid)-sum;                     //判断被包含的
        sum+=minn-sum;
        if(sumtop<sumbottom){
            top++;
            sumtop+=str1[top].n;
        }
        else if(sumtop>sumbottom){
            bottom++;
            sumbottom+=str2[bottom].n;
        }
        else if(sumtop==sumbottom){
            top++;
            sumtop+=str1[top].n;
            bottom++;
            sumbottom+=str2[bottom].n;
        }
    }
    cout<<ans;
    return 0;
}
