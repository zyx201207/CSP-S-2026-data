#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200009];
int b[200009][35];
int tf=0;
int happy(int x,int y){
    int anss=0,cnt=x;
    for(int i=x;i>=0;i--){
        anss=0;
        for(int j=0;j<y;j++){
            if(b[j][i]==1){
                anss++;
            }
        }
        if(anss==m){
            tf=1;
            return i;
        }
        if(anss>m){
            tf=0;
            return i;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int ls=a[i],lss=0;
        while(ls){
            b[i][lss]=ls%2;
            ls=ls/2;
            lss++;
        }
    }

    int oh=0;
    int ypl=0;
    int cnt=n;
    int ans=0,yc=0,jilu=0;
    ypl=happy(29,cnt);
    while(1){
        jilu=ypl;

        if(jilu==ypl){
            yc++;
        }
        //cout<<ypl<<'*'<<endl;
        if(tf==1){
            for(int i=0;i<n;i++){
                if(b[i][ypl]==1&&oh!=0){
                    ans=ans&a[i];
                    //cout<<ans<<"  "<<a[i]<<" | ";
                }
                if(oh==0){
                    ans=a[i];
                   // cout<<ans<<"##";
                    oh++;
                }
            }
            cout<<ans;
            return 0;
        }else{
            cnt=0;
            //cout<<"+";
            for(int i=0;i<n;i++){
                if(b[i][ypl]==1){
                    for(int j=29;j>=0;j--){
                        b[cnt][j]==b[i][j];

                    }
                    a[cnt++]=a[i];
                }
            }

        }
        if((ypl==0&&tf==0)||yc>=30){
            int ts=1;
            oh=0;
            for(int i=0;i<n;i++){
                if(b[i][ypl]==1&&oh!=0&&ts<=m){

                    ans=ans&a[i];
                   // cout<<a[i]<<"& ";
                    ts++;
                }
                if(oh==0){
                    ans=a[i];
                  //  cout<<ans<<"| ";
                    oh++;
                }
            }
           cout<<ans;
            return 0;
        }
        ypl=happy(ypl-1,cnt);
    }
    return 0;
}
