#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
const int N=5e5+10;
int n,m,a[N],pl[N];
map<int,int>mp;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];mp[a[i]]=i;	
	}
	for(int i=1;i<=n;i++){
		if(mp[a[i]]!=i){
			int pos=mp[a[i]];
			while(pos<=n){
				if(pos==i){
					pl[pos]++;
					pos++;
				}else if(mp[a[pos]]==pos){
					pl[pos]++;
					pos++;
				}else{
					pos=mp[a[pos]];
				}
			}
		}else{
			int pos=i;
			while(pos<=n){
				if(pos==i){
					pl[pos]++;
					pos++;
				}else if(mp[a[pos]]==pos){
					pl[pos]++;
					pos++;
				}else{
					pos=mp[a[pos]];
				}
			}
		}
	}                                       
	for(int i=1;i<=m;i++){
		cout<<pl[mp[i]]<<" ";
	}
	return 0;
}
