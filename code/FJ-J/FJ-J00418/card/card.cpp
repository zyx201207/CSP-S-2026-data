#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],Cnt[300005];
bool Sta[300005];
stack<int> s; 

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			Sta[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(Sta[a[j]]){
				while(s.top()!=a[j]){
					Sta[s.top()]=0;
					s.pop(); 
				}
			}else{
				s.push(a[j]);
				Sta[a[j]]=1;
			}
		}
		while(!s.empty()){
			Cnt[s.top()]++;
			//cout<<s.top()<<' ';
			s.pop();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<Cnt[i]<<' ';
	}
	return 0;
}
