//GZ-J00011 龙里县生态城实验学校 吴沛珊
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5;
ll m,n,a[N];
queue<ll> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(a[i]);
    }

    for(int i=1;i<=m;i++){
    	cout<<q.front()<<" ";
    	q.pop();
	}
    return 0;
}
