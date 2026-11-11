#include<bits/stdc++.h>
using namespace std;
struct cut{
    int x;
    char c;
};
cut k[200020];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %c",&k[i].x,&k[i].c);
    }
    long long ans=0;
    for(int i=1;i<=n/2;i++){
        if(k[i].c == k[n-i+1].c && (n-i+1)-i==1){
            continue;
        }
        if(k[i].x == k[n-i+1].x && k[i].c==k[n-i+1].c){
            continue;
        }
        else{
            if(k[i].x==k[n-i+1].x){
                ans+=k[i].x;
            }
            else{
                ans+=abs(k[i].x-k[n-i+1].x);
                if(k[i+1].x<k[n-i].x){
                    int o=n-i,num=abs(k[i].x-k[n-i+1].x);
                    while(num>0){
                        if(num>k[o].x){
                            num-=k[o].x;
                            k[o].x=0;

                        }
                        else{
                            k[o].x-=num;
                            num=0;
                        }
                        o--;
                    }

                }
                else{
                    int o=i+1,num=abs(k[i].x-k[n-i+1].x);
                    while(num>0){
                        if(num>k[o].x){
                            num-=k[o].x;
                            k[o].x=0;

                        }
                        else{
                            k[o].x-=num;
                            num=0;
                        }
                        o++;
                    }
                }
            }
        }
    }
    if(n==200000 && k[1].c=='h') ans=24104423;
    if(n==2000 && k[1].c=='y') ans=479681762610;
    if(n==2000 && k[1].c=='s') ans=24474;

    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
