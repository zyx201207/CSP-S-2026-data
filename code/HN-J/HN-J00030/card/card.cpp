#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void setio(string filename,string inSu=".in",string outSu=".out"){
	string in=filename+inSu;
	string out=filename+outSu;
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
}

const int MAXN=5010;
int cnts[MAXN]={0};
int list[MAXN]={0};
vector<int> map[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	setio("card");
	int num1,num2;
	scanf("%d",&num1,&num2);
	if(num1>5000)
		return 0;
	for(int i=1;i<=num1;i++){
		scanf("%d",&list[i]);
		for(int j=1;j<=i;j++){
			if(map[i].empty()){
				map[i].push_back(i);
			}
			else if(*upper_bound(map[i].begin(),map[i].end(),list[i])==list[i]){
				map[i].erase(upper_bound(map[i].begin(),map[i].end(),list[i]),map[i].end());
			}
			else{
				map[i].push_back(i);
			}
		}
	}
	for(int i=1;i<=num1;i++){
		for(auto it:map[i]){
			cnts[it]++;
		}
	}
	for(int i=1;i<=num2;i++){
		printf("%d ",cnts[i]);
	}
	return 0;
}
