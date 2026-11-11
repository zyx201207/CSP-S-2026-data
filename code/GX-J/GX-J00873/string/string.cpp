#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
struct Note{
    ull st=0;
    ull ed=0;
    char str;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ull n,h=0;
    vector<Note> T;
    cin>>n;
    for(ull i=0;i<n;i++){
        struct Note aa;
        cin>>aa.ed>>aa.str;
        if (i>0) {
                aa.st=T[i-1].ed;
                aa.ed+=T[i-1].ed;
        }
        T.push_back(aa);
    }
//    for(const Note& b : T){
//    cout<<b.st<<" "<<b.ed<<" "<<b.str<<"\n";}
//    cout<<"ok\n";
    //-------------
    long long l=0,r=T.size()-1;
    while(l<r){
        long long ca=(T[r].ed-T[r].st)-(T[l].ed-T[l].st);
        //cout<<ca<<" "<<T[r].ed-T[r].st<<" "<<T[l].ed-T[l].st;
        if (T[l].str!=T[r].str){
            if(ca>0){
                h+=T[l].ed-T[l].st;
                T[r].ed=T[r].st+ca;
                l++;
            }else if(ca<0){
                h+=T[r].ed-T[r].st;
                T[l].st=T[l].ed+ca;
                r--;
            }else{
                h+=T[l].ed-T[l].st;
                l++;
                r--;
            }
        }else{
            if(ca>0){
                T[r].ed=T[r].st+ca;
                l++;
            }else if(ca<0){
                T[l].st=T[l].ed+ca;
                r--;
            }else{
                l++;
                r--;
            }
        }
    }
//    for(const Note& b : T){
//    cout<<b.st<<" "<<b.ed<<" "<<b.str<<"\n";}
    cout<<h;
    return 0;
}
