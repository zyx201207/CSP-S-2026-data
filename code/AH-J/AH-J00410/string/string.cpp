#include<bits/stdc++.h>
using namespace std;
struct node{
    int sl;
    char c;
}a[200005];
int n;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].sl;
        cin>>a[i].c;
    }
    for(int l=1,r=n;1;l++,r--){
        if(l>=n){
            //cout<<"l>n\n";
            break;
        }
        //cout<<l<<" "<<r<<endl;
        if(a[l].c!=a[r].c){
            cnt+=(long long)max(a[l].sl,a[r].sl);
        }

//      3
//      2 a
//      1 b
//      1 a
/*
        if((a[l].c==a[r].c)&&(a[l].sl!=a[r].sl)){
            if(a[l].sl>a[r].sl){
                cnt+=(long long)a[l].sl;
                a[r-1].sl-=a[l].sl-a[r].sl;
            }
            if(a[l].sl<a[r].sl){
                cnt+=(long long)a[r].sl;
                a[l+1].sl-=a[r].sl-a[l].sl;
           }
        }
*/
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
