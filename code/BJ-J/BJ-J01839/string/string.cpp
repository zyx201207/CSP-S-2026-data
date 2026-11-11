#include<bits/stdc++.h>
using namespace std;
struct zdy{
    long long l,r;
    char c;
};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    vector<zdy> a(n);
    long long x;
    char y;
    long long z=0;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        zdy q;
        q.l=z;
        q.r=z+x-1;
        q.c=y;
        a[i]=q;
        z+=x;
    }
    //for(int i=0;i<n;i++){
   //     cout << a[i].l <<" " << a[i].r << endl;
   // }
    long long cnt=0;
    //for(int i=0;i<s.size()/2;i++){
    //    if(s[i]!=s[s.size()-1-i]){
    //        cnt++;
    //    }
   // }
   long long mi=0+a[a.size()-1].r;
    long long i=0,j=a.size()-1;
    while(i<j){
        long long cl=mi-a[i].l;
        long long cr=mi-a[i].r;
    //    cout << cr << " " << cl <<" " << a[j].l << " " << a[j].r<< endl;
        if(cr==a[j].l){
            if(a[i].c!=a[j].c){
                if(cl>a[j].r)
                    cnt+=a[j].r-cr+1;
                else
                    cnt+=cl-cr+1;
            }
            j--;
            i++;
            continue;
        }

        if(cr<a[j].l){
            if(cl>a[j].r){
                    //cout << "a";
                if(a[i].c!=a[j].c)
                    cnt+=a[j].r-a[j].l+1;
            }
            else{
               // cout << "b";
                if(a[i].c!=a[j].c)
                    cnt+=cl-a[j].l+1;

            }
            j--;
        }
        else{
            if(cl<a[j].r){
              //  cout << "c";
                if(a[i].c!=a[j].c){
                    cnt+=cl-cr+1;
                }
            }
            else{
               // cout << "d";
                if(a[i].c!=a[j].c){
                    cnt+=a[j].r-cr+1;
                }
            }
            i++;
        }

    }
    cout << cnt;
    return 0;
}
