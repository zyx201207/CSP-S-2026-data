#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int a[500005]; 
int b[500005];
queue<int> q;

void chack_clear(){
	int size=q.size();
	for(int i=1;i<=size;i++){
		q.pop();
	}
}

void move(int k){
	vector<int> v;
	int size_v;
	int size_q=q.size();
	for(int i=1;i<=size_q;i++){
		if(q.front()!=k){
			v.push_back(q.front());
			q.pop();
		}else{
			while(!q.empty()){
				q.pop();
			}
			size_v=v.size();
			for(int j=0;j<size_v;i++){
				q.push(v[i]);
			}
			break;
		}
		
	}
	q.push(k);
}

int main() {
	
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=m;i++){
		chack_clear();
		for(int j=i;j<=n;j++){
			int k=a[j];
			move(k);
		}
					
		int size=q.size();
		for(int i=1;i<=size;i++){
			b[q.front()]++;
			q.pop();
		}					
	}
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
}
