#include<bits/stdc++.h>
using nemrspace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char string c[10],cc[10],s[10],ss[10];
    int sum=0,siu=0,ans=0,can=0;
    for(int i=1;i<=2;i++) cin>>c[i]>>cc[i];
    for(int i=1;i<=3;i++) cin>>s[i]>>ss[i];
    for(int i=1;i<=2;i++) {
        if(c[i]==cc[i]&&c[i]!=1&&cc[i]!=1&&c[i]!=16&&cc[i]!=16) sum++;
    }
    if(sum==2) cout<<"1 ";
    else{
        cout<<"0 "<<"0 "<<"0 "<<"0";
        return 0;
    }
    for(int i=1;i<=2;i++){
        if(s[i]==ss[i]) siu++;
    }
    if(siu==2) cout<<"1 ";
    else{
        cout<<"0 "<<"0 "<<"0";
        return 0;
    }
    if(siu==2){
        if(s[3]=='A'||s[3]=='B'||s[3]=='C'){
            if(ss[3]=='A'||ss[3]=='B'||ss[3]=='C'){
                cout<<"1 ";
            }
        }
        else if(s[3]=='D'||s[3]=='F'){
            if(ss[3]=='D'||ss[3]=='F'){
            cout<<"1 ";
            }
        }
        else{
            cout<<"0 "<<"0";
            return 0;
        }
    }
    if((s[3]=='A'&&ss[3]=='B')||(ss[3]='A'&&s[3]=='B')||(s[3]=='B'&&ss[3]=='C')||(ss[3]='B'&&s[3]=='C')) cout<<"1";
    else if((s[3]=='D'&&ss[3]=='F')||(ss[3]='D'&&s[3]=='F')) cout<<"1";
    else cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}