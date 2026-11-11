#include<bits/stdc++.h>
using namespace std;
int a[1000000+10];
vector<int> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	map<int,int> w;
	int n,m,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long ans=0;
	while(n--){
		for(int i=cnt;i<=n;i++){
			bool y=false;
			int y1=0;
			for(int j=0;j<b.size();j++) if(a[i]==b[j]) y=true,y1=j;
			if(y==false){
				b.push_back(a[i]);
				continue;
			}
			else for(int j=y1;j<b.size();j++) b[j]=-1;
		}
		for(int i=0;i<b.size();i++) if(b[i]!=-1) w[b[i]]++;
		cnt++;
		for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
		cout<<endl;
		for(int i=0;i<b.size();i++) b[i]=0;
	}
	for(int i=1;i<=m;i++) cout<<w[m]<<" ";
	return 0;
}
