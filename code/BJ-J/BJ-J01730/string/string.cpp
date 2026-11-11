#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
    long long sum;
    char zi;
};
node a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        a[i].sum=x;
        a[i].zi=c;
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(a[i].zi!=a[i+1].zi&&i<=n-1){
            flag=false;
        }
    }
    if(flag){
        cout<<0;
        return 0;
    }
    for(int i=1,j=n;i<=n/2,j>=n/2;){
        if(i>n/2||j<n/2){
            break;
        }
        if(a[i].zi!=a[j].zi){
            num+=min(a[i].sum,a[j].sum);
            if(a[i].sum>a[j].sum){
                a[i].sum-=a[j].sum;
                j--;
            }
            else if(a[i].sum==a[j].sum){
                i++;
                j--;
            }
            else if(a[i].sum<a[j].sum){
                a[j].sum-=a[i].sum;
                i++;
            }
        }
        if(a[i].zi==a[j].zi){
            if(a[i].sum>a[j].sum){
                a[i].sum-=a[j].sum;
                j--;
            }
            else if(a[i].sum==a[j].sum){
                i++;
                j--;
            }
            else if(a[i].sum<a[j].sum){
                a[j].sum-=a[i].sum;
                i++;
            }
        }

    }
    cout<<num;



    fclose(stdin);
    fclose(stdout);
    return 0;
}



