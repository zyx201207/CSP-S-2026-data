#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,cnt[1<<19];
vector<ll>card,desk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	card.clear();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		card.push_back(x);
	}for(int i=0;i<n;i++){
		desk.clear();
		for(int j=i;j<n;j++){
			ll k=card[i],pos=-1;
			for(size_t j=0;j<desk.size();j++)
				if(desk[j]==k){
					pos=j;break;
			}if(pos!=-1)
                for(int l=desk.size()-pos;
					l>0;l--) desk.pop_back();
            desk.push_back(k);
		}for(size_t j=0;j<desk.size();j++)
            cnt[desk[j]]++;
	}for(int i=1;i<=m;i++)
        cout<<cnt[i]<<' ';
	return 0;
}
