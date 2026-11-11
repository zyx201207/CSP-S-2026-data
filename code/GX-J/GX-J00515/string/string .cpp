#include <bits/stdc++.h>
using namespace std;
string s;
char a;
long long n,m,ans;

struct y{
    long long num;
    char q;
}p[200005];
long long sizes;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].num;
        sizes+=p[i].num;
        cin>>p[i].q;

    }
    long long l=1,r=n;
    while(l<=r){

        if(p[l].q==p[r].q){
            if(p[l].num==p[r].num){
                l++,r--;
                continue;
            }
            else if(p[l].num<p[r].num){

                p[r].num=p[r].num-p[l].num;l++;
            }
            else {

                p[l].num=p[l].num-p[r].num;r--;
            }
        }
        else if(p[l].q!=p[r].q){
            if(p[l].num==p[r].num){
                l++,r--;
                ans+=p[l].num;
                continue;
            }
            else if(p[l].num<p[r].num){
                ans+=p[l].num;

                p[r].num=p[r].num-p[l].num;
                l++;

            }
            else {
                ans+=p[r].num;

                p[l].num=p[l].num-p[r].num;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;


}
