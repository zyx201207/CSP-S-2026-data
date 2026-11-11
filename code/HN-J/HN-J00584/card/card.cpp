#include<bits/stdc++.h>
using namespace std;
const int N=3e5+7;
int tj[N];
int x[N];
bool pd[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	queue<int>zp;	queue<int>k;	queue<int>yx;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}

	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++)zp.push(x[i]);
	while(!zp.empty()){
		int s=zp.front();
		zp.pop();
	
		if(pd[s]!=0){
			while(yx.front()!=s){
				k.push(yx.front());
				yx.pop();
			}
		    while(!yx.empty()){
		    	int ks=yx.front();
		    	pd[ks]=0;
		    	yx.pop();
			}
			while(!k.empty()){
				yx.push(k.front());
				k.pop();
			}
			yx.push(s);
			pd[s]=1;
		}
		else{
			yx.push(s);
			pd[s]=1;
		}
	}
	while(!yx.empty()){
		int qz=yx.front();
		tj[qz]++;
		pd[qz]=0;
		yx.pop();
			}
		}
		for(int i=1;i<=m;i++)cout<<tj[i]<<" ";
		
	
}
