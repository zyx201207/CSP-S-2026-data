#include <iostream>

using namespace std;
long long a[1000001],sum;
char x[1000000],y[1000000];
int main()
{
    freopen("string.in","w",stdin)
    freopen("string.out","r",stdout)
    int n;
    char c[10000000011];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            x[a[n-1]+1]=c[i];
        }

    }
    for(int i=n;i>0;i--){
        for(int j=0;j<a[i];j++){
             y[a[n+1]+1]=c[i];
        }
    }
    for(int k=0;k<n;k++){
        if(x[k]!=y[k]){
            sum++;
        }
    }
    cout<<sum;
    fclose(stdin)
    fclose(stdout)
    return 0;
}
