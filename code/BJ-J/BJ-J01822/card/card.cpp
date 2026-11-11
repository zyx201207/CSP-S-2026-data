#include<bits/stdc++.h>
using namespace std;
    int n,m,a[500005],book[300005],ans[300005],cnt=0;
    int st[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(book[a[j]]==1){
                //cout<<j<<' '<<book[a[j]]<<endl;
                while((st[cnt]!=a[j])&&cnt>0){
                    //cout<<st.size()<<' ';
                    book[st[cnt]]=0;
                    //st[cnt]=0;
                    cnt--;
                }
            }else {
                st[++cnt]=a[j];
                book[a[j]]=1;
            }
        }
        while(cnt>0){
            ans[st[cnt]]++;
            book[st[cnt]]=0;
            //st[cnt]=0;
            cnt--;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;}
