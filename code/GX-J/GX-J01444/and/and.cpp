#include <iostream>

using namespace std;
int a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,num=0,maxx=-1;
    int andd;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    num++;
    for(int i=0;i<n;i++){
        andd=andd|a[i];
        for(int j=i+1;j<n;j++){
            if(num==m){
                break;
            }
            andd&=a[j];
            num++;
        }
        if(maxx<andd){
           maxx=andd;
        }
        num=0;
        andd=0;
    }
    cout<<maxx;
    return 0;
}
