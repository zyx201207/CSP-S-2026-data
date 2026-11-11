#include<bits/stdc++.h>
using namespace std;
int n,m,c[300005];
vector<int>a;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	//cout<<"ok\n\n";//
	for(int i=0;i<n;i++){
		//cout<<"OK:";//
		vector<int>b;
		//int cnt=0;//
		for(int j=i;j<n;j++){
			if(!b.empty()&&a[j]==b.back()){
				//cnt++;//
				continue;
			}
			//cout<<cnt<<" ";//
			//cout<<i<<" "<<j<<"\n";//
			for(int k=0;k<b.size();k++){
				if(b[k]==a[j]){
					b.resize(k);
				}
			}
			b.push_back(a[j]);
		}
		//cout<<cnt<<"\n";//
		for(auto& j:b){
			c[j]++;
		}
		//cout<<flush;//
	}
	//cout<<'\n';//
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
}
