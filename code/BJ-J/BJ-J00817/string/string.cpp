#include<iostream>
#include<queue>
using namespace std;
struct str{
    long long a;
    char c;
};
deque<str> dq;
long long n,a,ans;
char c;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    while(n--){
        cin>>a>>c;
        dq.push_back({a,c});
    }
    while(dq.size()>1){
        str fr=dq.front(),bc=dq.back();

        if(fr.a>bc.a){
            if(fr.c!=bc.c) ans+=bc.a;
            dq.pop_back(),dq.pop_front(),dq.push_front({fr.a-bc.a,fr.c});
        }

        if(fr.a<bc.a){
            if(fr.c!=bc.c) ans+=fr.a;
            dq.pop_back(),dq.pop_front(),dq.push_back({bc.a-fr.a,bc.c});
        }

        if(fr.a==bc.a){
            if(fr.c!=bc.c) ans+=bc.a;
            dq.pop_back(),dq.pop_front();
        }
    }

    cout<<ans<<endl;

    return 0;
}