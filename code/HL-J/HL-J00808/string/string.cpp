# include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
#define int long long
int num[N];
char ch[N];

bool op(string a){
  string b =a;
reverse(a.begin(),a.end());
if(b==a) return 1;
else return 0;
}
int  op2(string a,string b){
    int lenth = a.size();
    int cnt =0;
for(int i=0;i<=lenth;i++){
        //cout<<a[i]<<" "<<b[i]<<endl;
    if(a[i]!=b[i]) cnt++;

}
return cnt;
}
int32_t main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    bool flag =1;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>ch[i];
        if(num[i] !=1000000000) flag =false;
    }
    if(!flag){
     for(int i=1;i<=n;i++){
        for(int j=1;j<=num[i];j++){
            s+=ch[i];
        }
    }
    }
    else {
         for(int i=1;i<=n;i++){
        for(int j=1;j<=num[i]/100000000;j++){
            s+=ch[i];
        }
    }
    }
    int lenth =s.size();
   /* if(s.size()-1<=10){
    int unsame = 0;
    if(op(s)){ cout<<"0"; return 0;}

    else {
         unsame = op2(s);
    }
    cout<<unsame ;
    }
    */
    int middle;
    string b =s;
     reverse(b.begin(),b.end());
     string left,right;

     if(op(s)){ cout<<"0"; return 0;}
     else {
        if(lenth%2!=0)
        {
            middle = (lenth/2)+1;
           for(int i=0;i<middle-1;i++){
            left+=s[i];
           }
           for(int i=middle;i<lenth;i++){
            right+=s[i];
           }
           // left = reverse(s.begin()+middle,a.end());

          //  cout<<left<<" " <<right<<endl;
            reverse(right.begin(),right.end());
          // cout<<left<<" " <<right<<endl;
            int ans = op2(left,right);
            if(!flag)
            cout<<ans;
            else {
                cout<<ans*100000000;
            }
        }
         else
        {
            middle = (lenth/2);
           for(int i=0;i<middle;i++){
            left+=s[i];
           }
           for(int i=middle;i<lenth;i++){
            right+=s[i];
           }
           // left = reverse(s.begin()+middle,a.end());

            //cout<<left<<" " <<right;
            reverse(left.begin(),left.end());
            int ans = op2(left,right);
            if(!flag)
            cout<<ans;
            else {
                cout<<ans*100000000;
            }
        }

     }

}
/*
  3
  2 a
  2 b
  1 c
  6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b
*/
