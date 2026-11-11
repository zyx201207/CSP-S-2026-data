#include<bits/stdc++.h>
using namespace std;
#define int long long
#define short int
short ca[200005];//paidui
short lie[200005];//meijvpailie
bool hace[100005];//meijvshifoufangzhi
int cnt[100005];//jichuxianzonshu
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ca[i];
	}
	for(int i=0;i<n;i++){
		memset(lie,0,sizeof(lie));
		memset(hace,0,sizeof(hace));
		short pai=0;
		for(int j=i;j<n;j++){
			lie[pai]=ca[j];
			if(hace[ca[j]]==1){
				lie[pai]=0;
				pai--;
				while(1){
					if(lie[pai]==ca[j]){
						lie[pai]=0;
						if(pai!=0)pai--;
						hace[ca[j]]=0;
						break;
					}
					lie[pai]=0;
					pai--;
				}
			}
			else {
				hace[ca[j]]=1;
				pai++;
			}
		}
		for(int i=0;i<pai+1;i++){
			cnt[lie[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
