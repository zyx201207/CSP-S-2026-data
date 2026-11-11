#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    int t=0,t2=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i=0;i<s1.length()-1;i++){
        t+=s1[i];
    }
    for(int i=0;i<s2.length()-1;i++){
        t2+=s2[i];
    }
    if(t!=t2){
        cout<<"1000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    t=s1[2];
    t2=s2[2];
    if((t=='C'&&t2=='D')||(t2=='C'&&t=='D')){
        cout<<"1100";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(t=='A'||t=='B'||t=='C'){
        if(t2=='A'||t2=='B'||t2=='C'){
            if(t2+1==t||t2-1==t){
                cout<<"1111";
                fclose(stdin);
                fclose(stdout);
                return 0;
            }else{
                cout<<"1110";
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
        }
    }else if(t=='D'||t=='F'){
        if(t2=='D'||t2=='F'){
            if(t2-1==t||t2+1==t){
                cout<<"1111";
                fclose(stdin);
                fclose(stdout);
                return 0;
            }else{
                cout<<"1110";
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
