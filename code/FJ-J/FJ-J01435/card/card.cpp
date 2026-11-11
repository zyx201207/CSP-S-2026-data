#include<bits/stdc++.h>
using namespace std;
size_t n,m;
vector<size_t>desktop,hand,ans;
bool repeat(vector<size_t>vec){
	for(size_t i=0;i<vec.size();i++){
		for(size_t j=i+1;j<vec.size();j++){
			if(vec[i]==vec[j]){
				return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	hand=vector<size_t>(n);
	ans=vector<size_t>(m,0);
	size_t n_=n;
	for(size_t i=0;i<n_;i++){
		cin>>hand[i];
		if(i!=0){
			if(hand[i-1]==hand[i]){
				hand.erase(hand.begin()+i);
				hand.erase(hand.begin()+(i-1));
				n_-=2;
				i-=2;
			}
		}
	}
	if(!repeat(hand)){
		for(size_t i=0;i<hand.size();i++){
			ans[hand[i]]=n;
		}
		for(const size_t&i:ans){
			cout<<i<<' ';
		}
		return 0;
	}
	printf("\n\n");
	for(const size_t&i:hand){
		printf("%zu ",i);
	}
	return 0;
	for(size_t times=0;times<hand.size();times++){
		desktop.clear();
		for(size_t i=times;i<n;i++){
			for(size_t&it:desktop){
				if(it==hand[i]){
					size_t l=desktop.size();
					for(size_t w=0;w<l;w++){
						auto pos_=desktop.begin()+(l-w-1);
						size_t data=*pos_;
						desktop.erase(pos_);
						if(data==hand[i]){
							break;
						}
					}
					break;
				}
			}
			desktop.push_back(hand[i]);
		}
		for(const size_t&i:desktop){
			ans[i-1]++;
		}
	}
	for(const size_t&i:ans){
		cout<<i<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
