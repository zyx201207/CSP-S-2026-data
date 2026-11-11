#include<bits/stdc++.h>
using namespace std;

queue<long long> d;
long long n,m,a[1000000],s,f=0,b[1000000];

int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int q=1;q<=d.size();q++){
				if(d.front()==a[j]){
					for(int w=1;w<=d.size();w++){
						if(d.front()!=s){
							d.pop();
						}else{
							f=1;
							break;
						}
					}
				}else{
					s=d.front();
					d.push(d.front());
					d.pop();
				}
					break;
				}
			}
			d.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<b[i];
}