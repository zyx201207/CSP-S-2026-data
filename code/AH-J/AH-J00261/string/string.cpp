#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
map<char,long long> q;
struct node{
    int x;
    char c;
};
int n;
string s;
long long sum;
node a[200005];
long long cnt;
void hw(string s){
    long long l=0,r=s.size()-1;
    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
        }else{
            cnt++;
            l++;
            r--;
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        for(int j=1;j<=a[i].x;j++){
            s+=a[i].c;
        }
    }
    hw(s);
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
