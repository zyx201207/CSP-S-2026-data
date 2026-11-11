#include <iostream>

using namespace std;
int a[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,sum=0,num=0,lo=0;
    bool yes=false;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int ij=1;ij<=m;ij++){
        for(int i=n-1;i>=0;i--){
            if(a[i]==ij){
               sum++;
               lo=i;
            }
            if(sum!=0&&a[i]!=ij){
                for(int j=i+1;j<n;j++){
                    if(a[j]==a[i]){
                        if(j<lo||i>lo){
                            break;
                        }
                        sum-=1;
                        break;
                    }
                }
                sum++;
            }
        }
        cout<<sum<<" ";
        sum=0;
    }
    return 0;
}
