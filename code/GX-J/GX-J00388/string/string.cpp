#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,sum=0;
    string s="";
    cin>>a;
    vector<long>t(a);
    vector<char>o(a);
    for(int i=0;i<a;i++){
        cin>>t[i]>>o[i];
    }
    int p=0,q=a-1;
    while(!(t[p+1]==0||t[q-1]==0||p==q)){
        if(o[p]==o[q]){
            if(t[p]>t[q]){
                t[p]-=t[q];
                t[q]=0;
                q--;
            }else
            if(t[p]<t[q]){
                t[q]-=t[p];
                t[p]=0;
                p++;
            }else
            if(t[p]==t[q]){
                t[p]=0;
                t[q]=0;
                q--;
                p++;
            }
        }else{
            if(t[p]>t[q]){
                t[p]-=t[q];
                sum+=t[q];
                t[q]=0;
                q--;
            }else
            if(t[p]<t[q]){
                t[q]-=t[p];
                sum+=t[p];
                t[p]=0;
                p++;
            }else
            if(t[p]==t[q]){
                sum+=t[p];
                t[p]=0;
                t[q]=0;
                q--;
                p++;
            }
        }
    }
    cout<<sum;
    return 0;
}
/*
        ________     ________
       / ______/    /_____  /
      / /                / /
     / /______          / /
    /  ____  /         / /
   / /    / /         / /
  / /____/ /         / /
 /________/         /_/
         ________     ________
       / ______/    /_____  /
      / /                / /
     / /______          / /
    /  ____  /         / /
   / /    / /         / /
  / /____/ /         / /
 /________/         /_/
         ________     ________
       / ______/    /_____  /
      / /                / /
     / /______          / /
    /  ____  /         / /
   / /    / /         / /
  / /____/ /         / /
 /________/         /_/
         ________     ________
       / ______/    /_____  /
      / /                / /
     / /______          / /
    /  ____  /         / /
   / /    / /         / /
  / /____/ /         / /
 /________/         /_/
 */
