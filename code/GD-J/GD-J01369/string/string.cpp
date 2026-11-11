#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int a[200001],c[200001];
    char ch;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>ch;
        c[i]=ch-'a';
    }
    int i=0,j=n-1;
    while(i<j){
        if(a[i]>a[j]){
            if(c[i]!=c[j])ans+=a[j];
            a[i]=a[i]-a[j];
            j--;
        }
        else{
            if(a[i]==a[j]){
                if(c[i]!=c[j])ans+=a[i];
                i++;
                j--;
            }
            else{
                if(c[i]!=c[j])ans+=a[i];
                a[j]=a[j]-a[i];
                i++;
            }
        }
    }
    cout<<ans;
//    fclose("string.in");
//    fclose("string.out");
    return 0;
}