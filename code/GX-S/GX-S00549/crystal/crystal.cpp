#include<bits/stdc++.h>
using namespace std;
int n,c;
long long m,a[1000005],ans,b,ant,sum;
int main(){
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n%2==0){
        c=n/2;
    }else{
        c=n/2+1;
    }
    for(int j=c-1,k=c+1;j>=1,k<=n;){
        ans=max(a[c]-a[j],a[k]-a[c]);
        if(m-ans>=0){
            if(a[c]-a[j]>a[k]-a[c]){
                k++;
                m-=ans;
                sum++;
            }else if(a[c]-a[j]==a[k]-a[c]){
                k++;
                j--;
                m-=2*ans;
                sum+=2;
            }else{
                j--;
                m-=ans;
                sum++;
            }
        }else{
            ant=min(a[c]-a[j],a[k]-a[c]);   
            if(m-ant>=0){
                if(a[c]-a[j]>a[k]-a[c]){
                    j--;
                    m-=ant;
                    sum++;
                }else{
                    k++;
                    m-=ant;
                    sum++;
				}
            }else{
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
