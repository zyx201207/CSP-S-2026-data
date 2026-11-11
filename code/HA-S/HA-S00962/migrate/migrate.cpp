#include<iostream>
#include<cstdio>
#include<vector>
//dfs jian zhi
using namespace std;
long long island[2000001]={0};
class node{
	public:
	vector<long long> to;
	node(){
		to.reserve(10);
	}
};
node nodes[2000001];
int mn=21000000,time=1;
void dfs(int n,int end,int bu){
	if(n==end){
		//cout<<bu<<endl;
		if(bu<mn){
			time=1;
			mn=bu;
		}else if(bu==mn){
			time++;
		}else{
		}
		return;
	}
	for(int i=0;i<nodes[n].to.size();i++){
		dfs(nodes[n].to[i],end,bu+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	long long d,n,ans=0;
	cin>>c>>t;
	for(int z=0;z<t;z++){
		ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>island[i];
			for(int j=i-1;j>=0;j--){
				if(d>=island[i]-island[j]){
					nodes[j].to.push_back(i);
				}else{
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<nodes[i].to.size();j++){
				//cout<<nodes[i].to[j]<<' ';
			}
			//cout<<endl;
		}
		for(int i=0,begin;i<n-2;i++){
			for(int j=i+2;j<n;j++){
				for(begin=i;nodes[begin].to.size()>1;begin++){}
				mn=21000000;
				time=1;
				dfs(begin,j,0);
				if(time==2){
					ans++;
					for(;nodes[j].to.size()<2;j++){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
		for(int i=0;i<n;i++){
			nodes[i].to.clear();
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
