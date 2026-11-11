//GZ-J00226 ·ëè÷ôË
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector<ll> hd,card;
ll summ[300000];
vector<bool> tmpsum;
ll card_down[300000];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	hd.push_back(-114514);
	card.push_back(-114514);
	for(int i=1;i<=n;i++){
        hd.push_back(0);
        cin>>hd[i];
	}

	for(int i=1;i<=n;++i){
        card.clear();
        card.push_back(-114514);
        tmpsum.clear();
        tmpsum.push_back(false);
        for(int j=i;j<=n;j++){
            if(card_down[hd[j]]>=1){
                for(int l=card.size()-1;l>=card_down[hd[j]];l--){
                    card_down[card[l]]=0;
                    card.pop_back();
                }
                card.push_back(hd[j]);
                card_down[hd[j]]=card.size()-1;
            }else{
                card.push_back(hd[j]);
                card_down[hd[j]]=card.size()-1;
            }
        }


        for(int j=1;j<=m;j++){
            tmpsum.push_back(false);
        }
        for(int j=1;j<=card.size()-1;j++){
            tmpsum[card[j]]=true;
        }
        for(int j=1;j<=m;j++){
            if(tmpsum[j])summ[j]++;

        }
	}
	for(int i=1;i<=m;i++){
        cout<<summ[i]<<" ";
	}
	return 0;
}
