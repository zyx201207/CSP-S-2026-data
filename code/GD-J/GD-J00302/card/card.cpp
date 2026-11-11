#include<bits/stdc++.h>
using namespace std;

int f(queue<int> a,int b){
	bool t=false;
	for(int i=0;i<a.size();i++){
		if(a.front()=b){
			t=i+1;
			break;
		}
		a.pop();
	}
	return t;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> pai;
	
	stack<int> gam;
	int q[m+1];
	for(int i=0;i<=n;i++){
		q[i]=0;
	}	 
	for(int i=0;i<n;i++){
		int o;
		cin>>o;
		pai.push_back(o);
	}
	int k=1;
	while(n){
		queue<int> ga;
		stack<int> gak;
		for(int i=k;i<pai.size();i++){
			int temp=pai[i];
			int m;
			m=f(ga,temp);
			if(f(ga,temp)){
				for(int lll=m;lll<=gam.size();lll++){
					gam.pop();
				}
			}
			ga.push(temp);
			gam.push(temp);	
			gak.push(temp);		
		}	
		for(int i=1;i<=m;i++){
			if(f(ga,i)){
				q[i]++;
			}
		}
		n--;
		k++;
	}
	for(int i=1;i<=m;i++){
		cout <<q[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
