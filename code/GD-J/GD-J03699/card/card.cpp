#include<iostream>
#include<stack>
using namespace std;
long long n,m,num[500005],dat[300005],ji=0,dj[500005];
bool used[500005];
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		dj[num[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) used[j]=0;
		for(int j=i;j<=n;j++){
			if(ji==100000000){
				for(int t=1;t<=m;t++){
					cout<<dj[t]<<' ';
				}
				return 0;
			}
			ji++;
			if(!used[num[j]]){
				used[num[j]]=1;
				q.push(num[j]);
			}
			else{			
				while(q.top()!=num[j]){
					ji++;
					used[q.top()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			dat[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<dat[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
