#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=501,maxm=20002;
ll w[maxm],k[maxn],c,n,m,d,q;
struct node{
    int st[maxm];
    int ti[maxm];
}a[maxn];
struct node1{
    int zt,tot[maxn],nx[maxn][3];
}kc[maxm];
int lj[maxm];
int fin(int s,int f,int al){
    lj[s]=1;
    int ch=2147483645;
    if(s==f){
        //cout<<s<<"->"<<f<<" line"<<al<<" "<<kc[f].tot[al]<<endl;
        return kc[f].tot[al];
    }
    for(int i=1;i<=n;i++){
        if(kc[s].nx[i][1]!=0&&lj[kc[s].nx[i][1]]==0){
            lj[kc[s].nx[i][1]]=1;
            int ls=fin(kc[s].nx[i][1],f,i);
            if(ls!=2147483645){
                if(al!=i&&al!=0)ch=min(ch,ls+kc[s].tot[al]+kc[s].tot[i]);
                //else if(al==0)ch=min(ch,ls+kc[s].tot[al]+kc[s].tot[i]+kc[s].tot[i]);
                else ch=min(ch,ls);
            }
            lj[kc[s].nx[i][1]]=0;
            //cout<<s<<"->"<<f<<" line"<<al<<" "<<ch<<endl;
        }
        if(kc[s].nx[i][2]!=0&&lj[kc[s].nx[i][2]]==0){
            lj[kc[s].nx[i][2]]=1;
            int ls=fin(kc[s].nx[i][2],f,i);
            if(ls!=2147483645){
                if(al!=i)ch=min(ch,ls+kc[s].tot[al]+kc[s].tot[i]);
                //else if(al==0)ch=min(ch,ls+kc[s].tot[al]+kc[s].tot[i]+kc[s].tot[i]);
                else ch=min(ch,ls);
            }
            lj[kc[s].nx[i][2]]=0;
            //cout<<s<<"->"<<f<<" line"<<al<<" "<<ch<<endl;
        }
    }
    lj[s]=0;
    return ch;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        kc[i].zt=w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i].st[j]>>a[i].ti[j];
            kc[a[i].st[j]].tot[i]=a[i].ti[j];
            if(j!=1)kc[a[i].st[j]].nx[i][1]=a[i].st[j-1];
            kc[a[i].st[j-1]].nx[i][2]=a[i].st[j];
        }
    }
/*
    for(int i=1;i<=m;i++){
        cout<<i<<":"<<endl;
        cout<<kc[i].zt<<endl;
        for(int j=1;j<=n;j++)cout<<kc[i].tot[j]<<" ";
        cout<<endl;
        for(int j=1;j<=n;j++)cout<<kc[i].nx[j][1]<<" "<<kc[i].nx[j][2]<<endl;
        cout<<"--------------------------------"<<endl;
    }*/
    for(int T=1;T<=q;T++){
        int start,finish;
        cin>>start>>finish;
        cout<<kc[start].zt+fin(start,finish,0)+kc[finish].zt<<endl;
    }
    return 0;
}
//16:30~17:59 0->[15,60)
