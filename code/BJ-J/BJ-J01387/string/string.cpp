#include<bits/stdc++.h>
using namespace std;
struct node{
    char ch;
    long long cnt;
};
vector<node> str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int xt;
    char cct;
    cin>>xt>>cct;
    str.push_back({cct,xt});
    for(int i=2;i<=n;i++){
        int x;
        char cc;
        cin>>x>>cc;
        if(cc==str.back().ch){
            str.back().cnt+=x;
        }
        else{
            str.push_back({cc,x});
        }
    }
    long long ans=0;
    for(int i=0,j=str.size()-1;i<=j;i++,j--){
        if(i==j)break;
        while(str[i].cnt==0)i++;
        while(str[j].cnt==0)j--;
        //cout<<i<<' '<<j<<'\n';
        if(str[i].ch!=str[j].ch){
            if(str[i].cnt>=str[j].cnt){
                ans+=str[j].cnt;
                str[j].ch=str[i].ch;
            }
            else{
                ans+=str[i].cnt;
                str[i].ch=str[j].ch;
            }
        }
        if(str[i].ch==str[j].ch){
            if(str[i].cnt==str[j].cnt)continue;
            if(str[i].cnt>str[j].cnt){
                long long tans=str[i].cnt-str[j].cnt;
                int k=j-1;
                while(tans>0){
                    if(str[k].ch==str[i].ch){
                        if(str[k].cnt<tans){
                            tans-=str[k].cnt;
                            str[k].cnt=0;
                        }
                        else{
                            str[k].cnt-=tans;
                            j=k+1;
                            break;
                        }
                        j=k;
                        k--;
                        continue;
                    }
                    if(str[k].cnt>=tans){
                        str[k].cnt-=tans;
                        ans+=tans;
                        j=k+1;
                        break;
                    }
                    tans-=str[k].cnt;
                    ans+=str[k].cnt;
                    str[k].cnt=0;
                    str[k].ch=str[i].ch;
                    j=k;
                    k--;
                }
            }
            else if(str[i].cnt<str[j].cnt){
                long long tans=str[j].cnt-str[i].cnt;
                int k=i+1;
                while(tans>0){
                    if(str[k].ch==str[j].ch){
                        if(str[k].cnt<tans){
                            tans-=str[k].cnt;
                            str[k].cnt=0;
                        }
                        else{
                            str[k].cnt-=tans;
                            i=k-1;
                            break;
                        }
                        i=k;
                        k++;
                        continue;
                    }
                    if(str[k].cnt>=tans){
                        str[k].cnt-=tans;
                        ans+=tans;
                        i=k-1;
                        break;
                    }
                    tans-=str[k].cnt;
                    ans+=str[k].cnt;
                    str[k].cnt=0;
                    str[k].ch=str[j].ch;
                    i=k;
                    k++;

                }
            }
        }

    }
    cout<<ans;
    return 0;
}
