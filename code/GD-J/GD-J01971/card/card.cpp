#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int crd[n];
	for(int i=0;i<n;i++){
		cin>>crd[i];
	}
	int cnt[m]={};
	for(int i=0;i<n;i++){
		vector<int>cards;
//		cout<<"round "<<i+1<<'\n';
		for(int j=i;j<n;j++){
			bool fnd=0;
//			cout<<"t="<<j+1<<": ";
			for(auto a:cards){
				if(a==crd[j]){
					fnd=1;
					break;
				}
			}
			if(fnd){
				for(int i=cards.size()-1;;i--){
					if(cards[i]==crd[j]){
//						cout<<"fnd ";
						break;
					}else{
//						cout<<"pop ";
						cards.pop_back();
					}
				}
			}else{
//				cout<<"push "<<crd[j]<<" ";
				cards.push_back(crd[j]);
			}
//			cout<<'\n';
		}
		bool hav[m]={};
		for(auto a:cards){
			if(!hav[a-1]){
				hav[a-1]=1;
			}
		}
		for(int i=0;i<m;i++){
			cnt[i]+=hav[i];
		}
//		cout<<'\n';
	}
//	cout<<'\n';
	for(auto a:cnt){
		cout<<a<<' ';
	}
	
	return 0;
}//i love simulation
