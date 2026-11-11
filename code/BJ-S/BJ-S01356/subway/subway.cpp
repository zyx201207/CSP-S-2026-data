#include<bits/stdc++.h>
using namespace std;

struct subway{
    int a[50010];
    int t[50010];
    int n;
};

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c1,n,m,d,q;
    cin>>c1>>n>>m>>d>>q;
    int w[m+1];
    w[0]=0;
    subway s[n];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        s[i].n=k;
        for(int j=0;j<k;j++){
            cin>>s[i].a[j]>>s[i].t[j];
        }
    }
    int x,y;
    int z;
    bool f=true;
    bool f1=true;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        int c=0;
        c+=w[x];
        c+=w[y];
        for(int j=0;j<n;j++){
            for(int k=0;k<s[j].n;k++){
                if(s[j].a[k]==x){
                    c+=s[j].t[k];
                    z=j;
                }
            }
        }

        for(int j=0;j<n;j++){
            for(int k=0;k<s[j].n;k++){
                f1=true;
                if(s[j].a[k]==y){
                    c+=s[j].t[k];
                    if(j==z){
                        cout<<c<<endl;
                        f1=false;
                        break;
                    }
                    else{
                        f=true;
                        for(int j=0;j<n;j++){
                            for(int k=0;k<s[j].n;k++){
                                for(int r=j+1;r<n;r++){
                                    for(int e=0;e<s[r].n;e++){
                                        //cout<<s[r].a[e]<<" "<<s[j].a[k]<<endl;
                                        if(s[r].a[e]==s[j].a[k]){
                                            c+=s[r].t[e];
                                            c+=s[j].t[k];
                                            cout<<c<<endl;
                                            f=false;
                                            break;
                                        }
                                        if(f==false) break;
                                    }
                                    if(f==false) break;
                                }
                                if(f==false) break;
                            }
                            if(f==false) break;
                        }
                        if(f==false) break;
                    }
                    if(f==false) break;
                }

            }
            if(f1==false) break;
        }
    }

    return 0;
}
