#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<int>e(n);
vector<int>im(n,0);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);\


    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>e[i];
        for(int j=i;j>=0;j--)
        {
            if(e[j]>e[j-1]){
                swap(e[j],e[j-1]);
            }
            else{
                break;
            }
        }
    }
    int w=m;
    int x=1;
    for(int i=0;i<n-1;i++)
    {
        w=m;x=1;
        while((w>0)&&(i+x<=n-1)){
            if(w>=(e[i]-e[i+x]))
            {
                w=w-e[i]+e[i+x];
            }
            else{
                w=0;
            }
        }
        im[i]=x;
    }
    int ma=im[0];
    for(int i=0;i<n;i++)
    {
        if(im[i]>ma){
            ma=im[i];
        }
    }
    cout<<ma;

return 0;

}
