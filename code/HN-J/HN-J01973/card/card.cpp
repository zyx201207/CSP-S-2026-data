#include<bits/stdc++.h>
using namespace std;
int n,m,b[500001],c[300001];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	set <int> a;
	cin >> n >> m;
	for(int i= 1;i<=n;i++){
		cin >> b[i];
	}
	for(int i=1;i<=n;i++){
		//cout << "第" << i <<"轮游戏"<<endl;
		a.clear();
		for(int j=i;j<=n;j++){
			if(a.count(b[j])){
				//cout <<"因为有" << b[j];
				a.clear();
				//cout <<"消除" <<" ";
			}
			a.insert(b[j]);
			//cout << "插入" <<b[j] <<" ";
		}
		for(int j=1;j<=m;j++){
           if(a.count(j)){
           	c[j]+=1;
           	//cout << "计数" <<j <<"+1"<<" ";
		   } 
		   cout << endl;
		}
	}
	for(int i =1; i<=m;i++)	cout << c[i] <<" ";
	return 0;
}
