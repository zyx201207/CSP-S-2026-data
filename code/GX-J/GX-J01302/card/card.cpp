#include<bits/stdc++.h>

using namespace std;

int n,m,a[200005];

struct aa{

    int s,w;

    bool f=0;

};

int m1[100005];

void aaa(int i){

    aa s[m+5];

    int z[n],wz=0;

    for(int j=i;j<=n;j++){

        z[wz]=a[j];

        if(s[a[j]].f==1){

            wz=s[a[j]].w;

        }else{

            s[a[j]].f=1;

            s[a[j]].w=wz;

        }

        wz++;

        //for(int j=0;j<wz;j++){

         //   cout<<z[j]<<" ";

        //}

        //cout<<endl;

    }

    bool aaaa[m+5]={0};

    for(int j=0;j<wz;j++){

        if(aaaa[z[j]]!=0)continue;

        m1[z[j]]++;

        aaaa[z[j]]=1;

    }

}

int main(){

    freopen("card.in","r",stdin);

    freopen("card.out","w",stdout);

    cin>>n>>m;

   for(int i=1;i<=n;i++){

        cin>>a[i];

   }

    for(int i=1;i<=n;i++){

        aaa(i);

    }

    for(int i=1;i<=m;i++){

        cout<<m1[i]<<" ";

    }

    return 0;

}
