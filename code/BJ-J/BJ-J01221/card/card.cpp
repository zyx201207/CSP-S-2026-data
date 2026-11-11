#include<bits/stdc++.h>
using namespace std;
long long n,m,b=0,c=0,d=0;
int a[500005];
queue<int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int x=0,p=0;
        for(int j=i;j<n;j++){
            int y=x;
            while(y--){
                if(q.front()==a[j]){
                    p=1;
                }
                if(p==1){
                    q.pop();
                    x--;
                }
            }
            if(p==0){
                q.push(a[i]);
                x++;
            }
        }
        while(!q.empty()){
            if(q.front()==1) b++;
            if(q.front()==2) c++;
            if(q.front()==3) d++;
            q.pop();
        }
    }
    cout<<b<<' '<<c<<' '<<d;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
