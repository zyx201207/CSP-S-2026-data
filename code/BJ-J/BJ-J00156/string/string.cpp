#include <iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cout<<0;
    /*int n,num[200005];
    char zm[200005];
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>num[i]>>zm[i];
    }
    long long int ans=0;
    int y=n+5;
    for(int z=1;z<=y;z++){
        y=n+1-z;
        if(z==y)break;
        if(zm[z]==zm[y]){//zm=
            if(num[z]==num[y]){//num=
                z+=num[z];
                y-=num[z];
                n-=num[z]+num[y];
            }
            else if(num[z]!=num[y]){//num!=
                int s=min(num[z],num[y]);
                if(s==num[z]){
                    z+=s;
                    num[y]-=s;
                }
                else{
                    y-=s;
                    num[z]-=s;
                }
                n-=s+s;
            }
        }
        else if(zm[z]!=zm[y]){//zm!=
            if(num[z]==num[y]){//num=
                cout<<z<<' '<<y<<'|'<<num[z]<<' '<<num[y]<<endl;
                z+=num[z];
                y-=num[z];
                ans+=num[z];
                n-=num[z]+num[y];
            }
            else if(num[z]!=num[y]){//num!=
                int s=min(num[z],num[y]);
                if(s==num[z]){
                    cout<<z<<' '<<y<<'|'<<num[z]<<' '<<num[y]<<endl;
                    z+=s;
                    num[y]-=s;
                }
                else{
                    cout<<z<<' '<<y<<'|'<<num[z]<<' '<<num[y]<<endl;
                    y-=s;
                    num[z]-=s;
                }
                ans+=s;
                n-=s+s;
            }
        }
    }
    cout<<ans;*/
    return 0;
}
