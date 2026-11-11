#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<long long>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s.begin(),s.end());
    vector<long long>cha(n);
    for(int i=0;i<n-1;i++){
        cha[i]=s[i+1]-s[i];
    }
    int l=0,r=0;
    long long res=0,len=0;
    for(int i=0;i<n-1;i++){
		res+=cha[i]*(r-l+1);
		r++;
        while(res>m){
            res-=s[r]-s[l];
            l++;
        }
        len=max(len,(long long)r-l+1);
    }
    cout<<len;
    return 0;
}
