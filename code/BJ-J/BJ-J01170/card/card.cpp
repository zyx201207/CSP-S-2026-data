#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> cnt(m+1,0);
    for(int i=1;i<=n;i++){
        deque<int> q;
        vector<int> b(m+1,0);
        for(int j=i;j<=n;j++){
            q.push_back(a[j]);
            if(b[a[j]]==0){
                b[a[j]]=1;
                //cout<<"line20"<<endl;
            }
            else{
                deque<int> q2;
                while(q.front()!=a[j]){
                    //cout<<"first while\n";
                    q2.push_back(q.front());
                    q.pop_front();
                }
                //cout<<"line29\n";
                q.pop_front();
                //cout<<"line31\n";
                while(q.front()!=a[j]){
                    b[q.front()]=0;
                    //cout<<"pop "<<q.front()<<"\n";
                    q.pop_front();
                    //cout<<"l36\n";
                }
                //cout<<"line38\n";
                while(!q2.empty()){
                    q.push_front(q2.back());//cout<<"running the third while\n";
                    q2.pop_back();
                }
                // cout<<"line43\n";
                // for(int k=0;k<q.size();k++){
                //     cout<<q[k]<<" ";
                // }
                // cout<<endl;
            }
        }
        while(!q.empty()){
            cnt[q.front()]++;
            //cout<<q.front()<<" ";
            q.pop_front();
        }
        //cout<<"\n";
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}