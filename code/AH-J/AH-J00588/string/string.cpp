#include<bits/stdc++.h>
using namespace std;
char c[1010010];
int a[1010100];long long sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int j=n;
    int i=1;
    while(i<j){
        if(a[i]>a[j]&&c[i]!=c[j]){
            a[i]-=a[j];
            sum+=a[j];
            j--;
        }
        else if(a[i]<a[j]&&c[i]!=c[j]){
            a[j]-=a[i];
            sum+=a[i];
            i++;
        }
        else if(a[i]==a[j]&&c[i]!=c[j]){
            sum+=a[i];
            i++;
            j--;
        }
        else if(c[i]==c[j]&&a[i]>a[j]){
            a[i]-=a[j];
            j--;
        }
        else if(c[i]==c[j]&&a[i]<a[j]){
            a[j]-=a[i];
            i++;
        }
        else {
            i++;
            j--;
        }
    }
    cout<<sum;
    return 0;
}
