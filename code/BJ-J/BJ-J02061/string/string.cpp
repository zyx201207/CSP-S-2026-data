#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
const long long MAXN=2e5+5;
using namespace std;
long long n;
struct str{
    long long a;
    string c;
}str[MAXN];
int main(){
    freopen("string3.in","r",stdin);
    freopen("string3.out","w",stdout);

    cin>>n;
    long long len=0;
    for(long long i=1;i<=n;i++){
        cin>>str[i].a>>str[i].c;
        len+=str[i].a;
    }
    long long cnt=0;
    long long nl=1,nr=n;
    while(nr!=nl){
        //cout<<str[nl].a<<' '<<str[nl].c<<' '<<str[nr].a<<' '<<str[nr].c<<' ';
        //cout<<endl;
        if(str[nl].a==0)nl++;
        if(str[nr].a==0)nr--;
        long long cmp=min(str[nl].a,str[nr].a);
        if(str[nl].c!=str[nr].c)cnt+=cmp;
        str[nl].a-=cmp;
        str[nr].a-=cmp;
        //cout<<str[nl].a<<' '<<str[nl].c<<' '<<str[nr].a<<' '<<str[nr].c<<' ';
        //cout<<endl;
        //cout<<"------------"<<endl;
    }
    //cout<<endl;
    cout<<cnt;
    return 0;
}
