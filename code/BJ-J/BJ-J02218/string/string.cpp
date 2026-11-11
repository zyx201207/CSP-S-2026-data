#include<bits/stdc++.h>
using namespace std;
int n;
long long L=0,ans=0;
string s;
long long a[100005];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>s[i];
        L+=a[i];
    }
    int i=0,j=n-1;
    while(i<=j){
        if(a[i]>a[j]){
            a[i]-=a[j];
            if(s[i]!=s[j])ans+=a[j];
            j--;
        }
        else if(a[i]==a[j]){
            if(s[i]!=s[j])ans+=a[i];
            j--;
            i++;
        }
        else{
            a[j]-=a[i];
            if(s[i]!=s[j])ans+=a[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
