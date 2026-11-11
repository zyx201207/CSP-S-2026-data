#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,zk,qi,k,zo,aann=9999999,t=0;
struct zhan{
    long long s1;
    long long s2[510];
}z[500000];
int zoo(int ll,int gg,int rr){
    int aa=z[ll].s2[rr];
    int ans=999999999;
     for(int i=1;i<=n;i++){
		// if(t=1){
            //    return 0;
		//	 break;
		// }
//tai nan le ,qi si wo le

            if(z[gg].s2[i]>0&&z[ll].s2[i]>0){
                ans=z[zo].s2[i];
                t=1;
            }else{
            if(z[ll].s2[i]>0){
                for(int o=1;o<=m;o++)
                if(z[o].s2[i]>0){
                    if(t=1){
                        break;
                    }
                        zoo(o,zo,i);
                        if(t=1){
                            aa=aa*2+zoo(o,zo,i);
                            if(aa<ans)
                          ans=aa;
                         aa=z[ll].s2[rr];
                break;
                        }

                }//if(t=1){
                  //  return 0;

			// break;
		// }
            }
            if(aa<ans)
             ans=aa;
            aa=z[ll].s2[rr];
            }

     }t=0;
     return ans;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    cin>>z[i].s1;
}
for(int i=1;i<=n;i++){
        cin>>k;
      for(int qw=1;qw<=k;qw++){
          cin>>zk;
    cin>>z[zk].s2[qw];
      }

}
for(int i=1;i<=q;i++){
    cin>>qi>>zo;
    for(int u=1;u<=n;u++){
        if(z[qi].s2[u]>0){
            if(aann>zoo(qi,zo,u)+z[qi].s1+z[zo].s1){
                aann=zoo(qi,zo,u)+z[qi].s1+z[zo].s1;
            }
        }
    }cout<<aann<<endl;t=0;
aann=999999999999;
}

return 0;
}
