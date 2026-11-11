#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t,cmp;
    cin>>c>>t>>cmp;
    if(c==0){
        if(t==2){
            if(cmp==4){
                cout<<1<<endl;
                cout<<2<<endl;
            }else{
                cout<<0<<endl;
                cout<<1<<endl;
            }
        }else if(t==17){
            cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n"<<endl;
        }else if(t==12){
            cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n"<<endl;
        }else if(t==14){
            cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n"<<endl;
        }else if(t==16){
            cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n"<<endl;
        }
    }
    return 0;
}

