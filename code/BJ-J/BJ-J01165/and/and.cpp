#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    long long maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==n){
            maxn=a[1];
    int i=2;
    n--;
        while(n--){
            maxn&=a[i];
    i++;
        }
    }else if(m==1){
        maxn=a[n];
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(a[i]&a[j]>maxn){
                    maxn=a[i]&a[j];
                }
            }
        }
    }else if(m=n-1){
        maxn=a[n];
    int i=n-1;
    m--;
        while(m--){
            maxn&=a[i];
    i--;
        }
    }else if(n<=20){
        if(m==1){
            cout<<a[n];
        }else if(m==2){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    if(i&ia>maxn){
                        maxn=i&ia;
                    }
                }
            }
        }else if(m==3){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                        for(int ib=1;ib<ia;ib++){
                    if(i&ia&ib>maxn){
                        maxn=i&ia&ib;
                    }
                        }
                }
            }
        }else if(m==4){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is;
                    }

                        }
                        }
                        }

            }
        }else if(m==5){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is;
                    }
                    }
                    }
                        }

                }
            }
        }else if(m==6){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is;
                    }

                        }
                        }
                        }
                        }

                }
            }
        }else if(m==7){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    if(i&ia&ib&ic&id&ie&ig>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig;
                    }

                        }
                        }
                        }
                        }
                        }

                }
            }
        }else if(m==8){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    if(i&ia&ib&ic&id&ie&ig&ih>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih;
                    }

                        }
                        }
                        }
                        }
                        }
                        }

                }
            }
        }else if(m==9){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii;
                    }

                        }
                        }
                        }
                        }
                        }

                        }
                        }
                }
            }
        }else if(m==10){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij;
                    }

                        }
                        }
                        }
                        }
                        }
                        }
                        }

                        }
                }
            }
        }else if(m==11){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik;
                    }

                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                }
            }
        }else if(m==12){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    for(int il=1;il<ik;il++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il;
                    }

                        }
                        }
                        }
                        }
                        }
                        }

                        }
                        }
                        }
                        }
                }
            }
        }else if(m==13){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    for(int il=1;il<ik;il++){
                    for(int im=1;im<il;im++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im;
                    }

                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }

                }
            }
        }else if(m==14){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    for(int il=1;il<ik;il++){
                    for(int im=1;im<il;im++){
                    for(int in=1;in<im;in++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in;
                    }

                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }

                }
            }
        }else if(m==15){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    for(int il=1;il<ik;il++){
                    for(int im=1;im<il;im++){
                    for(int in=1;in<im;in++){
                    for(int io=1;io<in;io++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io;
                    }

                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }

                }
            }
        }else if(m==16){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    for(int il=1;il<ik;il++){
                    for(int im=1;im<il;im++){
                    for(int in=1;in<im;in++){
                    for(int io=1;io<in;io++){
                    for(int ip=1;ip<io;ip++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip;
                    }

                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }

                        }
                        }
                        }
                }
            }
        }else if(m==17){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    for(int il=1;il<ik;il++){
                    for(int im=1;im<il;im++){
                    for(int in=1;in<im;in++){
                    for(int io=1;io<in;io++){
                    for(int ip=1;ip<io;ip++){
                    for(int iq=1;iq<ip;iq++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq;
                    }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }

                }
            }
        }else if(m==18){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    for(int il=1;il<ik;il++){
                    for(int im=1;im<il;im++){
                    for(int in=1;in<im;in++){
                    for(int io=1;io<in;io++){
                    for(int ip=1;ip<io;ip++){
                    for(int iq=1;iq<ip;iq++){
                    for(int ir=1;ir<iq;ir++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir;
                    }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }

                }
            }
    }else if(m==19){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    for(int il=1;il<ik;il++){
                    for(int im=1;im<il;im++){
                    for(int in=1;in<im;in++){
                    for(int io=1;io<in;io++){
                    for(int ip=1;ip<io;ip++){
                    for(int iq=1;iq<ip;iq++){
                    for(int ir=1;ir<iq;ir++){
                            for(int is=1;is<ir;is++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is;
                    }

                            }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }

                }
            }
    }else if(m==20){
            for(int i=1;i<=n;i++){
                for(int ia=1;ia<i;ia++){
                    for(int ib=1;ib<ia;ib++){
                    for(int ic=1;ic<ib;ic++){
                    for(int id=1;id<ic;id++){
                    for(int ie=1;ie<id;ie++){
                    for(int ig=1;ig<ie;ig++){
                    for(int ih=1;ih<ig;ih++){
                    for(int ii=1;ii<ih;ii++){
                    for(int ij=1;ij<ii;ij++){
                    for(int ik=1;ik<ij;ik++){
                    for(int il=1;il<ik;il++){
                    for(int im=1;im<il;im++){
                    for(int in=1;in<im;in++){
                    for(int io=1;io<in;io++){
                    for(int ip=1;ip<io;ip++){
                    for(int iq=1;iq<ip;iq++){
                    for(int ir=1;ir<iq;ir++){
                            for(int is=1;is<ir;is++){
                                    for(int it=1;it<is;it++){
                    if(i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is&it>maxn){
                        maxn=i&ia&ib&ic&id&ie&ig&ih&ii&ij&ik&il&im&in&io&ip&iq&ir&is&it;
                    }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }
                        }

                }
            }
    }else{
        maxn=a[n];
        int i=n-1;
        m--;
        while(m--){
            maxn&=a[i];
            i--;
        }
    }

    cout<<maxn<<" ";
    return 0;
}
