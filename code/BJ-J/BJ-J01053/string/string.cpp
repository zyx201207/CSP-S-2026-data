#include<bits/stdc++.h>
using namespace std;
struct zfc{
    long long ans;
    string name;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].ans>>a[i].name;
        sum+=a[i].ans;
    }
    if(sum%2!=0){
        long long sum1=0;
        for(int i=1;i<=n;i++){
            sum1+=a[i].ans;
            if(sum1>sum/2){
                a[i].ans--;
                break;
            }
        }
    }
    long long daan=0;
    for(int i=1,j=n;i<j;){
        if(a[i].name==a[j].name){
            if(a[i].ans==a[j].ans){
                i++,j--;
            }
            else if(a[i].ans>a[j].ans){
                a[i].ans-=a[j].ans;
                j--;
            }
            else{
                a[j].ans-=a[i].ans;
                i++;
            }
        }
        else{
            if(a[i].ans==a[j].ans){
                daan+=a[i].ans;
                i++,j--;
            }
            else if(a[i].ans>a[j].ans){
                daan+=a[j].ans;
                a[i].ans-=a[j].ans;
                j--;
            }
            else{
                daan+=a[i].ans;
                a[j].ans-=a[i].ans;
                i++;
            }
        }

    }
    cout<<daan;
    return 0;
}
