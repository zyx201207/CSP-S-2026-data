#include<bits/stdc++.h>
using namespace std;
string s;
long long sum;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        int o;
        char p;
        cin>>o>>p;
        for(int i=0;i<o;i++){
            s+=p;
        }
    }
    int i=0,l=s.length();
    for(;i<=l;){
        if(s[i]!=s[l]) sum+=1;
        i++;l--;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
