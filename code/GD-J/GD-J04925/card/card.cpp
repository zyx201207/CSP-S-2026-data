#include<iostream>
#include<queue>
using namespace std;
int n,m,a[100010],jilu1[50005],jilu2[50005],ans[50005];
bool b=false;
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		jilu1[a[i]]++;
		if(jilu1[a[i]]>1){
			jilu2[a[i]]==a[i];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0+i;j<=n;j++){
			for(int k=1;k<=q.size();k++){
				int h;
				h=q.front();
				q.pop();
				if(h==a[j]){
					b=true;
					break;
				}
				else{
					q.push(h);
				}
			}
			if(b){
				while(!q.empty()){
					q.pop();
				}
				q.push(a[j]);
			}
			else{
				q.push(a[j]);
			}	
			b=false;
			
			
		}
		while(!q.empty()){
			ans[q.front()]++;
			//cout<<q.front()<<" ";
			q.pop();
		}
		
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
