#include<bits/stdc++.h>
using namespace std;

int T,C;
int n,d,a[2010],ans;

bool isk(int x,int y){
    int aa=a[y]-a[x],ans1=0;
    if(aa<d)return false;
    if(aa%d==0)return false;
    for(int i=x;i<=y;i++)
        if(a[i]-a[x]<=d&&a[y]-a[i]<=d)ans1++;
    if(ans1==2)return true;
    else return false;

}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>C>>T;
    for(int i=1;i<=T;i++){
        ans=0;
        cin>>n>>d;
        for(int o=1;o<=n;o++)cin>>a[o];
        for(int j=1;j<=n;i++){
            for(int k=j+1;k<=n;k++)
                if(isk(j,k)==true){
                    ans++;
                }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}

