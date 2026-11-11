#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int a,m,n=0,q=0,p=0,o=0,t=0;
    cin >> a>>m;
    int s[a]={},d[a]={};
    for(int i=0;i<=a-1;i++){
        cin >> s[i];
        n+=s[i];
    }
    sort(s+0,s+a);
  //  for(int i=0;i<=a-1;i++)cout << s[i]<<"  ";
 //   cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        int w= 99999999999999,r=-1;
        for(int i=0;i<=a-2;i++){
             d[i]= s[i+1]-s[i];

            if(d[i]<w&&d[i]!=0){
                w=min(w,d[i]);
                r=i;

            }
    //       cout << d[i]<<"  ";

        }
   //     cout <<endl;cout <<endl;cout <<endl;
        //


     while(m>0){





        for(int i=1;i<=a-1;i++){
            if (d[i]==d[0]){
                    o++;
                }
            }
        if (o==a){
            m=0;
            cout << a;
            t++;
            break  ;
        }



        int w= 99999999999999,r=-1;
        for(int i=0;i<=a-2;i++){
             //d[i]= s[i+1]-s[i];

            if(d[i]<w&&d[i]!=0){
                w=min(w,d[i]);
                r=i;

            }

 //          cout << d[i]<<"  ";

        }
  //      cout <<endl;





 //       cout << r<<"  ";


        if(r!=-1){
           m-=d[r];
           if(m<=0)break;
           d[r]=0;



            //
            for(int i=1;i<=a-1;i++){
                if (d[i]==d[0]){
                    o++;
                }
            }
            if (o==a){
                m=0;
                cout << a;
                t++;
                break  ;
            }


    //break;

        }

 // /      cout <<endl;
 //       cout << m<<"  ";
 //      cout <<endl;

//       for(int i=0;i<=a-2;i++){

  //         cout << d[i]<<"  ";

//        }
    //   cout <<"_";
       for(int i=1;i<=a-1;i++){
            if (d[i]==d[0]){
                   o++;
                }
            }
        if (o==a){
            m=0;
            cout << a;
            t++;
            break  ;
        }



    }


 //   cout <<endl<<"_______________________"<<endl;
    for(int i=0;i<=a-1;i++){
        if(d[i]==0){
            p++;
        }
        else{
            q=max(p,q);
            p=0;
        }
    }


    if(t==0) cout<< q+1<<"  " << endl;
   // cout<< q+1<<"  " << endl;















    fclose(stdin);
    fclose(stdout);
    return 0;
}
