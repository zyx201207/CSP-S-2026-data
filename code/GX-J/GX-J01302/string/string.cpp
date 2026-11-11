#include<bits/stdc++.h>

using namespace std;

struct aa{

    long long a;

    char c;

}a[200005];

int n;

long long h;

long long aa1(){


    int l=0,r=n-1;

    long long ans=0;

    while(r!=l){

        if(a[l].c!=a[r].c){

            if(a[l].a>a[r].a){

                ans+=a[r].a;

                a[l].a-=a[r].a;

                r--;

            }else{

                ans+=a[l].a;

                a[r].a-=a[l].a;

                l++;

            }

        }else{

            if(a[l].a>a[r].a){

                a[l].a-=a[r].a;

                r--;

            }else{

                a[r].a-=a[l].a;

                l++;

            }

        }

    }

    return ans;

}

int main(){

    freopen("string.in","r",stdin);

    freopen("string.out","w",stdout);

    cin>>n;

    for(int i=0;i<n;i++){

        cin>>a[i].a>>a[i].c;

        h+=a[i].a;

    }

    cout<<aa1();

    return 0;

}
