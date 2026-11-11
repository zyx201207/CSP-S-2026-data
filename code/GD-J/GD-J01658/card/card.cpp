#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio> 
using namespace std;
int a[500005];
stack<int>d;
stack<int>s;
int c[100005];
int b[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(n<=100005){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(b[a[j]]!=0){
					while(!s.empty()){
						if(s.top()==a[j]){
							break;
						}
						b[s.top()]--;
						s.pop();
						
					}
				}else{
					s.push(a[j]);
					b[a[j]]++;
				}
			}
			while(!s.empty()){ 
				c[s.top()]++;
				s.pop();
			}
			memset(b,0,sizeof(b)); 
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
	}
	
	return 0;
}
