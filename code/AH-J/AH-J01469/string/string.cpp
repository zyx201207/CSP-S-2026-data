#include<bits/stdc++.h>
using namespace std;
struct zfc {
    long long a;
    char c;
};
int main(){
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    long long n,sum=0,e,s=0,l1=0,l2=0;
    zfc k[100001];
    char z1,z2;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> k[i].a >> k[i].c;
    }
    e=n-1;
    while (1){
        if(e<=s){
            cout << sum;
            break;
        }
        if (l1!=0){
            if (z1!=k[e].c){
                if (l1>k[e].a){
                    sum+=k[e].a;
                    l1-=k[e].a;
                    e--;
                }else if (l1<k[e].a){
                    sum+=l1;
                    l2=k[e].a-l1;
                    z2=k[e].c;
                    s++;
                }else{
                    sum+=l1;
                    s++;
                    e--;
                    l1=0;
                }
            }else{
                if (l1>k[e].a){
                    l1-=k[e].a;
                    e--;
                }else if (l1<k[e].a){
                    l2=k[e].a-l1;
                    z2=k[e].c;
                    s++;
                }else{
                    s++;
                    e--;
                    l1=0;
                }
            }
            continue;
        }else if (l2!=0){
            if (z2!=k[s].c){
                if (l2>k[s].a){
                    sum+=k[s].a;
                    l2-=k[s].a;
                    s++;
                }else if (l2<k[s].a){
                    sum+=l2;
                    l1=k[s].a-l2;
                    z1=k[s].c;
                    e--;
                }else{
                    sum+=l2;
                    s++;
                    e--;
                    l1=0;
                }
            }else{
                if (l2>k[s].a){
                    l2-=k[s].a;
                    s++;
                }else if (l2<k[s].a){
                    l1=k[s].a-l2;
                    z1=k[s].c;
                    e--;
                }else{
                    s++;
                    e--;
                    l1=0;
                }
            }
            continue;
        }
        if (k[s].c!=k[e].c){
            if(k[s].a>k[e].a){
                sum+=k[e].a;
                l1=k[s].a-k[e].a;
                z1=k[s].c;
                e--;
            }else if (k[s].a<k[e].a){
                sum+=k[s].a;
                l2=k[e].a-k[s].a;
                z2=k[e].c;
                s++;
            }else{
                sum+=k[s].a;
                s++;e--;
            }
        }else{
            if(k[s].a>k[e].a){
                l1=k[s].a-k[e].a;
                z1=k[s].c;
                e--;
            }else if (k[s].a<k[e].a){
                l2=k[e].a-k[s].a;
                z2=k[e].c;
                s++;
            }else{
                sum+=k[s].a;
                s++;e--;
            }
        }
    }
    return 0;
}
