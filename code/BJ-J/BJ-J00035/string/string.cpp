#include<bits/stdc++.h>

using namespace std;
struct{
    long long num;
    char c;
}a[1000005];
long long sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].num>>a[i].c;
    }
    int l=0,r=n-1;
    while(l!=r && !( a[l].num==0 && a[r].num==0 && r-l==1)){
            if(a[l].c==a[r].c){
                if(a[l].num>a[r].num){
                    int p=a[r].num;
                    a[l].num-=p;
                    a[r].num-=p;
                    r--;
                }else if(a[l].num<a[r].num){
                    int p=a[l].num;
                    a[l].num-=p;
                    a[r].num-=p;
                    l++;
                }else{
                    a[l].num=0;
                    a[r].num=0;
                    l++,r++;
                }
            }else{
                if(a[l].num>a[r].num){
                    int p=a[r].num;
                    a[l].num-=p;
                    a[r].num-=p;
                    r--;
                    sum+=p;
                }else if(a[l].num<a[r].num){
                    int p=a[l].num;
                    a[l].num-=p;
                    a[r].num-=p;
                    l++;
                    sum+=p;
                }else{
                    sum+=a[l].num;
                    a[l].num=0;
                    a[r].num=0;
                    l++,r++;

                }
            }
    }
    cout<<sum;
    return 0;
}
