#include<iostream>
#include<stack>
using namespace std;
struct nums{
	int num;
	bool use;
	int t;
}b[300001];
int main(){
	stack<int>a;
	int n,m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		b[i].t=0;
		b[i].use=1;
	}
	int k[500000];
	for(int i=0;i<n;i++){
		cin>>k[i];
		b[k[i]].num=k[i];
		if(b[k[i]].use){
			b[k[i]].use=0;
			a.push(k[i]);
		}else{
			while(a.top()!=k[i]){
				b[a.top()].use=1;
				a.pop();
			}
		}
	}
	while(!a.empty()){
		b[a.top()].t++;
		b[a.top()].use=1;
		a.pop();
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			b[k[j]].num=k[j];
			if(b[k[j]].use){
				b[k[j]].use=0;
				a.push(k[j]);
			}else{
				while(a.top()!=k[j]){
					b[a.top()].use=1;
					a.pop();
				}
			}
		}
		while(!a.empty()){
			b[a.top()].t++;
			b[a.top()].use=1;
			a.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i].t<<' ';
	}
	return 0;
}
