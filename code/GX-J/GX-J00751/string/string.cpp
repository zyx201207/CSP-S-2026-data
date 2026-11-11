#include <iostream>

using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    //cout << "Hello world!" << endl;
    int n,pp=0;
    scanf("%d",&n);long long s=0;
    int m[100000];
    char c[100000];char e;
    for(int i=1;i<=n;i++){
            scanf("%d%s",&m[i],&c[i]);
        //cin>>c[i];
        if(i==1){
            e=c[i];
        }
        if(e!=c[i]){
            pp++;
        }
    }
    if(pp==0)
    {
        cout<<"0";return 0;
    }
    int j=n,l=1;
    while(j>l){
            //if(c[j]!=c[l]){
                int uu=0;
    if(c[j]!=c[l])uu++;
                if(m[j]>m[l]){
                    m[j]-=m[l];
                    if(uu==1){
                        s+=m[l];
                    }

                    l++;
                }else{
                m[l]-=m[j];
                if(uu==1){
                        s+=m[j];
                    }

                j--;

                }
                if(m[l]==0)
                {

                    l++;
                }
            //}

    }
    cout<<s;
    return 0;
}
