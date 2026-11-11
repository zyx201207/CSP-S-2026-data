#include <bits/stdc++.h>
using namespace std;

struct NODE{
    int cd;
    char c;
};NODE arr[200010];
int n,ans=1e9;string s,s1,s2,s4;

void fz(){
    string s3=s1;
    for(int i=0;i<(int)s.size();i++){
        s1[i]=s3[(int)s.size()-1-i];
    }
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].cd>>arr[i].c;
        while(arr[i].cd!=0){
            arr[i].cd--;
            s+=arr[i].c;
        }
    }
    s1=s;fz();string pd=s;
    if(s1==pd) {
        cout <<0;
        return 0;
    }
    for(int i=0;i<(int)s.size();i++){
        char c=s[i];int sum=0;bool flag=false;
        s1=s;
        for(int j=0;j<(int)s.size();j++){
            if((j==(int)s.size()/2 or s1[j]==s1[(int)s.size()/2]) and s[j]==c) continue;
            else{
                sum++;
                s1[i]=c;
            }
            if(s1[(int)s.size()/2+1]!=s1[(int)s.size()/2] and (int)s.size()>4){
                s1[(int)s.size()/2+1]=s1[(int)s.size()/2];
                sum++;
            }
            if(s1[(int)s.size()/2-1]!=s1[(int)s.size()/2] and (int)s.size()>4){
                s1[(int)s.size()/2-1]=s1[(int)s.size()/2];
                sum++;
            }
            s4=s1;
            fz();
            s2=s1;
            if(s4==s2) {
                flag=true;
                break;
            }
        }
        if(flag) ans=min(sum,ans);
    }
    cout << ans-1;
}
