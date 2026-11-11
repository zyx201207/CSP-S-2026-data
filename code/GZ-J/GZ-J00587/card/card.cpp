//GZ-J00587 六盘水市第二十四中学 许浩然 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	queue<int>s;
	int a[n]={};
	for(int i=0;i<n;i++){
		int h;
		cin>>h;
		s.push(h);
	}
//	第i+1局 
	for(int i=0;i<n;i++){
		int c=0 /*需消数*/,f=0;
		int b[n+1][n+1]={},a[m+1];
		for(int j=0;j<s.size();j++){
			if(b[s.front()][0]==0){
				b[s.front()][0]++;
				for(int k=1;k<=n;k++){
					if(b[k][0]==1){
						b[s.front()][k]++;
					}
				}
			}
			if(b[s.front()][0]==1){
				for(int k=1;k<=n;k++){
					if(b[s.front()][k]==1){
						for(int v=1;v<=n;v++){
							b[v][k]==0;
						}
					}
				}
				b[s.front()][0]==0;
			}
			s.push(s.front());
			s.pop();
		}
		for(int j=1;j<=n;j++){
			if(b[j][0]==1){
				a[j]++;
			}
		}
		s.pop();
		if(s.size()==0){
			break;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
