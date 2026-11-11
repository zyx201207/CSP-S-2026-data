#include<bits/stdc++.h>
using namespace std;
struct stu{
    long long a;
    string c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    stu st[200005];
    cin>>n;
    long long i=1;
    for(i;i<=n;i++){
        cin>>st[i].a>>st[i].c;
    }
    long long cnt=0;
    int indexn=n;
    for(int i=1;i<=n;i++){
            if(i==indexn-i+1||i>indexn-i+1)
                {
                    cout<<cnt;
                    return 0;
                }
        if(st[i].c!=st[indexn-i+1].c){
            if(st[i].a==st[indexn-i+1].a)
            {
                    cnt+=st[i].a;
            }
            else{
                cnt+=min(st[i].a,st[indexn-i+1].a);
                if(st[i].a<st[indexn-i+1].a){
                    st[indexn-i+1].a-=min(st[i].a,st[indexn-i+1].a);
                    indexn++;
                }
                else{
                    st[i].a-=min(st[i].a,st[indexn-i+1].a);
                    i--;
                    indexn--;

                }
            }

        }
        else{
            if(st[i].a!=st[indexn-i+1].a){
                indexn++;
                st[indexn-i].a-=min(st[i].a,st[indexn-i].a);
            }
            else{
                    st[i].a-=min(st[i].a,st[indexn-i+1].a);
                    i--;
                    indexn--;

                }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
