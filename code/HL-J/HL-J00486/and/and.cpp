#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,n=0,m=0;
    cin>>a>>b;
    int s[a-1];
    //cout<<a<<endl;
    for(int i=0;i<=a-1;i++){
        cin>>s[i];
    //    cout<<0<<' ';
    }

    //cout<<endl;cout<<endl;cout<<endl;
    for(int i=0;i<=a-1;i++){

     //   cout<<s[i]<<' ';
        m=max(m,s[i]);
    }
   // cout<<endl;cout<<endl;cout<<endl;
    if(b==1)cout<<m;
    else{







    for(int i=0;i<=a-2;i++){
        for(int j=1;j<=a-1;j++){
            //cout<<s[i]<<"   "<<s[j];
            if(i!=j){
                n=max(n,(s[i]&s[j]));
     //           cout<<i<<"   "<<j<<"        "<<(s[i]&s[j]);
            }

      //      cout<<endl;

        }
    }




    //cout<<endl;cout<<endl;cout<<endl;
    cout<<n<<' ';

   // cout<<(31&1)<<' ';
    }
    //else cout<<0<<' '<<0<<' '<<0<<' '<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//5 3
//31 3 1 15 7



