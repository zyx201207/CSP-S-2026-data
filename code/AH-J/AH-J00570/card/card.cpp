#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,e;
int a[N],v[N];
int fs[N],fe[N];
int ans[M];
struct node{
    int st,ed;
}lst[M];
bool cmp(node x,node y){
    if(x.st!=y.st){
        return x.st<y.st;
    }
    return x.ed<y.ed;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        lst[a[i]].st=lst[a[i]].ed;
        lst[a[i]].ed=i;
    }
    //cout<<m<<"\n";
    for(int i=1;i<=m;i++){
        //cout<<i<<" ";
        if(lst[i].st==0){
            lst[i].st=lst[i].ed;
            v[lst[i].ed]=3;
            //cout<<i<<" : "<<lst[i].st<<"~"<<lst[i].ed<<"\n";
            continue;
        }
        v[lst[i].st]=1;
        v[lst[i].ed]=2;
        //cout<<i<<" : "<<lst[i].st<<"~"<<lst[i].ed<<"\n";
    }

    for(int i=1;i<=n;i++){
        fs[i]=fs[i-1],fe[i]=fe[i-1];
        if(v[i]==1){
            fs[i]=fs[i-1]+1;
        }else if(v[i]==2){
            fe[i]=fe[i-1]+1;
        }else if(v[i]==3){
            fs[i]=fs[i-1]+1;
            fe[i]=fe[i-1]+1;
        }
        //cout<<v[i]<<"   ";
        //cout<<i<<" : "<<fs[i]<<" "<<fe[i]<<"\n";
    }
    sort(lst+1,lst+1+m,cmp);
    /*
    for(int i=1;i<=m;i++){
        cout<<i<<" : ";
        cout<<lst[i].st<<"~"<<lst[i].ed<<"\n";
    }
    */
    for(int i=1;i<=n;i++){
        e=i;
        //cout<<i<<"\n";
        for(int j=1;j<=m;j++){
            //cout<<j<<":";
            //cout<<lst[j][0]<<" "<<lst[j][1]<<"\n";
            //cout<<ed<<" ";
            if(lst[j].ed<e){
                //cout<<"t1\n";
                continue;
            }
            if(lst[j].st<e){
                int idx=lst[j].ed;
                if(fs[idx]==fe[idx]){
                    ans[j]++;
                }
                //cout<<"t2\n";
                continue;
            }
            e=lst[j].ed;
            ans[j]++;
            //cout<<"t3\n";
        }
        /*
        cout<<i<<":\n";
        for(int j=1;j<=m;j++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        */
        //cout<<"\n";
        //cout<<ed<<" ";
        //cout<<"\n\n";
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
