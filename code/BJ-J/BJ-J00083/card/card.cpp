#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int card[500005];
int ans[300005];
int st[500005];
int vis[500005];
int tp=0;
void add(int x){
    st[tp++]=x;
}
bool pop(){
    if(tp>0){
        tp--;
        return true;
    }else{
        return false;
    }
}
int top(){
    return st[tp-1];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
		tp=0;
		//cout<<"in round "<<i<<endl;
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
			int k=card[j];
			//cout<<"card:"<<k<<endl;
            if(vis[card[j]]>0){
				
                while(top()!=card[j]){
					vis[top()]--;
                    pop();
                }
            }else{
                add(card[j]);
                vis[card[j]]++;
            }
        }
        for(int i=1;i<=tp;i++){
            ans[st[i-1]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
