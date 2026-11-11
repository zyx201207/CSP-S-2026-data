#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	queue<int>s;
	for(int i=1;i<=n;i++){
		int r;
		cin>>r;
		s.push(r);
	}
	queue<int>d;
	for(int i=1;i<=m;i++){
		int e=0;
		while(e!=s.size()){
			int f=s.front();
			s.pop();
			if(f!=i){
				d.push(f);
				a[f]++;
				e++;
			}else{
				while(!s.empty()){
					s.pop();
				}
				break;
			}
		}
		while(d.empty()){
			s.push(d.front());
			d.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
