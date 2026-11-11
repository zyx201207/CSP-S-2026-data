#include<iostream>
#include<string>
using namespace std;

//bool is(string s){for(size_t i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()-i-1]) return false;return true;}
/*
unsigned f(string s){
    if(is(s)) return 0;
    unsigned res=0x7fffffff;
    for(size_t i=s.size()/2+1;i<s.size();i++){
        if(s[i]!=s[s.size()-i+1]){
            char old=s[i];
            s[i]=s[s.size()-i+1];
            res=min(f(s)+1,res);
            s[i]=old;
        }
    }
    return res;
}*/

typedef size_t Tp;

struct dan{
    Tp a;
    char b;
};

class mys{
    char *c;
    Tp *times;
    Tp now;
    Tp si;
    Tp ma;
public:
    mys(Tp s):now(0),si(0),ma(s){c=new char[s+10]();times=new Tp[s+10]();}
    ~mys(){delete[] c;delete[] times;}
    Tp size()const{return si;}
    mys& operator+=(dan d){si+=d.a;/*if(now!=0&&c[now-1]==d.b){times[now-1]+=d.a;return *this;}*/times[now]=d.a;c[now++]=d.b;return *this;}
    char operator[](Tp s)const{
        //if(s>=this->size()) return -1;
        Tp res=0;
        Tp i=0;
        while(res+times[i]-1<s||res>s) res+=times[i++];//cerr<<(res+=times[i++])<<' '<<s<<endl;
        return c[res];
    }
    char at(Tp s)const{return c[s];}
    operator const char*()const{return c;}
};

Tp f(const mys& s){
    Tp res=0;
    Tp si=s.size(),ha=si/2;
    //cout<<si<<' '<<ha<<endl;
    //cerr<<si<<' '<<ha;
    //cerr<<s[0]<<endl;//for(int i=100000;i<si;i++)cout<<i<<' '<<s[i]<<endl;
    for(Tp i=0;i^ha;i++)if(s[i]^s[si-i-1])res++;//cerr<<res++<<endl;else cerr<<res<<endl;
    return res;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    mys s(n);
    Tp a;char b;
    dan d;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        d.a=a;d.b=b;
        s+=d;
        //cout<<d.a<<d.b<<' ';
        cout<<s<<' ';
        //cout<<s.size()<<' '<<a<<b<<int(s[s.size()-a+1])<<' '<<(s.at(i))<<endl;
    }
    cout<<s<<' ';
    //cout<<s<<endl;
    cout<<f(s);
    //cout<<endl;
    return 0;
}
