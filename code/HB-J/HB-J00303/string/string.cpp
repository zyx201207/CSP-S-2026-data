#include<bits/stdc++.h>
using namespace std;
int a[100005];
char b[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int sum=0;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        for(int j=sum;j<=sum+a[i]-1;j++){
            s[j]=b[i];
        }
        sum=sum+a[i];
    }
    int count=0;
    for(int i=0;i<=(1+n)/2;i++){
        if(s[i]!=s[n-i-1]){
            count++;
        }
    }
    cout<<count;
    fclose(stdin);
    fclose(stdout);
    return 0;
}