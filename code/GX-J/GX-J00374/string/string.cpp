#include<bits/stdc++.h>
using namespace std;
string a,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num;
    cin>>n;
    string s,m;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        cin>>m;
        for(long long j=0;j<num;j++){
            s+=m;
        }
    }
    long long number=0;
    if(s.size()%2==0){
        if(s.substr(0,(s.size())/2)==s.substr((s.size())/2,s.size())){
            cout<<number;
        }
        else{
            for(long long i=0;i<s.size()/2;i++){
                a=s[i];
                int j=0;
                j=s.size()-1-i;
                b=s[j];
                if(a==b){
                    number+=0;
                }
                else{
                    number+=1;
                }
            }
            cout<<number;
        }
    }
    else{
        if(s.substr(0,(s.size())/2)==s.substr((s.size())/2+1,s.size())){
            cout<<number;
        }
        else{
            for(long long i=0;i<s.size()/2;i++)
            {
                a=s[i];
                int j=0;
                j=s.size()-1-i;
                b=s[j];
                if(a==b){
                    number+=0;
                }
                else{
                    number+=1;
                }
            }
            cout<<number;
        }
    }
}
