#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],c[200005],ans=0;
char b[200005];
/*void dfs(long long p){
    if(p==2)return;
    for(int i=1;i<=n;i++){
        if(c[i]==c[i+1]){
            a[i]+=a[i+1];
            a[i+1]=0;
            c[i+1]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]!=0&&a[i]!=0){
            c[v]=c[i];
            a[v]=a[i];
            v++;
            l=1;
        }
    }

    for(int i=v;i<=n;i++){
        a[i]=0,c[i]=0;
    }
    if(p==0)p=2;
    dfs(p);
}*/
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int l=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(b[i]!=b[i-1])l=1;
    }
    if(n==1){
        cout<<"0";
        return 0;
    }
    if(n==2&&l==1){
        cout<<min(a[1],a[2]);
        return 0;
    }
    if(n==2&&l==0){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(b[i]=='a'){
            c[i]=1;
        }else if(b[i]=='b'){
            c[i]=2;
        }else if(b[i]=='c'){
            c[i]=3;
        }else if(b[i]=='d'){
            c[i]=4;
        }else if(b[i]=='e'){
            c[i]=5;
        }else if(b[i]=='f'){
            c[i]=6;
        }else if(b[i]=='g'){
            c[i]=7;
        }else if(b[i]=='h'){
            c[i]=8;
        }else if(b[i]=='i'){
            c[i]=9;
        }else if(b[i]=='j'){
            c[i]=10;
        }else if(b[i]=='k'){
            c[i]=11;
        }else if(b[i]=='l'){
            c[i]=12;
        }else if(b[i]=='m'){
            c[i]=13;
        }else if(b[i]=='n'){
            c[i]=14;
        }else if(b[i]=='o'){
            c[i]=15;
        }else if(b[i]=='p'){
            c[i]=16;
        }else if(b[i]=='q'){
            c[i]=17;
        }else if(b[i]=='r'){
            c[i]=18;
        }else if(b[i]=='s'){
            c[i]=19;
        }else if(b[i]=='t'){
            c[i]=20;
        }else if(b[i]=='u'){
            c[i]=21;
        }else if(b[i]=='v'){
            c[i]=22;
        }else if(b[i]=='w'){
            c[i]=23;
        }else if(b[i]=='x'){
            c[i]=24;
        }else if(b[i]=='y'){
            c[i]=25;
        }else if(b[i]=='z'){
            c[i]=26;
        }
    }
  //  dfs(0);
   /* for(int i=1;i<=v;i++){
        cout<<a[i]<<" "<<c[i]<<endl;
        }
*/

    for(int i=1;i<=n/2;i++){
        if(c[i]==c[n-i+1]&&a[i]!=a[n-i+1]){
            ans+=max(a[i]-a[n-i+1],a[n-i+1]-a[i]);
            continue;
        }else if(a[i]==a[n-i+1]&&c[i]!=c[n-i+1]){
            ans+=a[i];
            continue;
        }else if(c[i]==c[n-i+1]&&a[i]==a[n-i+1]){
            ans+=0;
            continue;
        }else{
            ans+=max(a[i],a[n-i+1]);
            if(a[i]>a[n-i+1]){
                if(a[n-i]-a[i]+a[n-i+1]>=0){
                    a[n-i]=a[n-i]-a[i]+a[n-i+1];
                    continue;
                }else{
                    a[n-i]=-a[n-i]+a[i]-a[n-i+1];
                    continue;
                }
            }else{
                if(a[i+1]=a[i+1]+a[i]-a[n-i+1]>=0){
                   a[i+1]=a[i+1]+a[i]-a[n-i+1];
                   continue;
                }else{;
                    a[i+1]=-a[i+1]-a[i]+a[n-i+1];
                    continue;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
