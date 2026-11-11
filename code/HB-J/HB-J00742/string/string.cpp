#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long ans=0;
pair<int,char> w[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i].first>>w[i].second;
	}
	int i=1,j=n;
	while(i<j){
		if(w[i].first==w[j].first){
			if(w[i].second!=w[j].second) ans+=w[i].first;
			i++,j--;
		}
		else{
			if(w[i].first>=w[j].first){
				if(w[i].second!=w[j].second) ans+=w[j].first;
				w[i].first-=w[j].first;
				j--;
			}
			else{
				if(w[i].second!=w[j].second) ans+=w[i].first;
				w[j].first-=w[i].first;
				i++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
