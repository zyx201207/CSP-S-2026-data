#include<bits/stdc++.h>
using namespace std;
int a,b,c[500005],d[300005],e[300005];
vector<int>v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}for(int i=1;i<=a;i++){
		memset(d,0,sizeof(d));
		v.clear();
		for(int j=i;j<=a;j++){
			if(d[c[j]]==1){
				int r=v.size()-1;
				while(v[r]!=c[j]){d[v[r]]=0;v.erase(v.begin()+r);r--;}
				d[c[j]]=0;v.erase(v.begin()+r);
			}v.push_back(c[j]);
			d[c[j]]=1;
		}for(auto v1:v){
			//cout<<v1<<' ';
			e[v1]++;
		}//cout<<endl;
	}
	for(int i=1;i<=b;i++){
		cout<<e[i]<<' ';
	}return 0; 
}
