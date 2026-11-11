#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,sum,l,r,k,cnt,a[2222222];
bool b[2222222];
void dfs(long long x,long long y){
    if(y==k){
        if(x==r) sum++;
        return;
    }for(int i=x-1;i&&a[x]-a[i]<=d;i--){
        b[i]=1;
        dfs(i,y+1);
        b[i]=0;
    }for(int i=x+1;i<=n&&a[i]-a[x]<=d;i++){
        b[i]=1;
        dfs(i,y+1);
        b[i]=0;
    }return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        cnt=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(l=1;l<n;l++){
            for(r=l+1;r<=n;r++){
                for(k=2;k<=n;k++){
                    dfs(l,1);
                    if(sum==2) cnt++;
                    if(sum) break;
                }sum=0;
            }
        }cout<<cnt<<'\n';
    }return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
bool b[2][5][15];
int x,jp,cnt[5];
string a[5][30],s,s1;
bool cmp(string x,string y){
    int xx,yy;
    if(x[1]=='A') xx=14;
    else if(x[1]<='9') xx=x[1]-'0';
    else if(x[1]=='T') xx=10;
    else if(x[1]=='J') xx=11;
    else if(x[1]=='Q') xx=12;
    else if(x[1]=='K') xx=13;
    else if(x[1]=='D') xx=17;
    else if(x[1]=='X') xx=16;
    else xx=20;
    if(y[1]=='A') yy=14;
    else if(y[1]<='9') yy=y[1]-'0';
    else if(y[1]=='T') yy=10;
    else if(y[1]=='J') yy=11;
    else if(y[1]=='Q') yy=12;
    else if(y[1]=='K') yy=13;
    else if(y[1]=='D') yy=17;
    else if(y[1]=='X') yy=16;
    else yy=20;
    if(xx==jp) xx=15;
    if(yy==jp) yy=15;
    return (bool)(xx<yy||(xx==yy&&x[0]<y[0]));
}
int main(){
    srand(time(0));
    while(1){
        for(int i=1;i<5;i++) for(int j=1;j<30;j++) a[i][j]="@@";
        s="@@";
        cin>>jp;
        getline(cin,s1);
        while(cnt[1]+cnt[2]+cnt[3]+cnt[4]<108){
            for(int i=1;i<5;i++){
                int x=rand()%2,y=rand()%5,z=rand()%13+1;
                if(y==0) z%=2;
                while(b[x][y][z]){
                    x=rand()%2,y=rand()%5,z=rand()%13+1;
                    if(y==0) z%=2;
                }b[x][y][z]=1;
                a[i][++cnt[i]][0]=y+'0';
                if(y==0){
                    if(z) a[i][cnt[i]][1]='D';
                    else a[i][cnt[i]][1]='X';
                }else{
                    if(z==1) a[i][cnt[i]][1]='A';
                    else if(z<10) a[i][cnt[i]][1]=z+'0';
                    else if(z==10) a[i][cnt[i]][1]='T';
                    else if(z==11) a[i][cnt[i]][1]='J';
                    else if(z==12) a[i][cnt[i]][1]='Q';
                    else a[i][cnt[i]][1]='K';
                }
            }
        }for(int i=1;i<5;i++) sort(a[i]+1,a[i]+cnt[i]+1,cmp);
        x=0;
        while(1){
            for(int i=1;i<5;i++){
                cout<<endl<<"Player"<<i<<endl;
                for(int j=1;j<=cnt[i];j++) if(a[i][j][0]!='@') cout<<a[i][j][0]<<a[i][j][1]<<' ';
                cout<<endl;
                getline(cin,s1);
                for(int i=0;i<s1.size();i+=3){
                    s[0]=s1[i];
                    s[1]=s1[i+1];
                    for(int j=1;j<=cnt[i];j++) if(a[i][j]==s) a[i][j]="@@";
                }sort(a[i]+1,a[i]+cnt[i]+1,cmp);
            }
        }
    }
    return 0;
}*/
