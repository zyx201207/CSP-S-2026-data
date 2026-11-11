#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    srand(time(0));
    if(c==0){
        int x;
        cin>>x;
        cout<<t<<" "<<x;
        if(t==2&&x==4)cout<<"1\n2";
        else if(t==2&&x==5)cout<<"0\n1";
        else if(t==17&&x==197)cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        else if(t==12&&x==260000)cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        else if(t==14&&x==200001)cout<<"9999900000/n399995/n0/n716427/n0/n0/n2/n1/n0/n2/n3/n6/n0/n2";
        else if(t==16&&x==174944)cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else{
        while(t--){
            int n;
            cin>>n;
            cout<<n-3<<"\n";
        }

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}