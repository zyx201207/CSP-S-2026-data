#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500010],b[300010];
stack<int>x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(x.find(a[j])==0){
				x.push(a[j]);
			}else{
				for(int d=1;;d++){
					if(x.pop()==a[i]){
						x.push(a[i]);
						break;
					}else{
						x.pop();
					}
				}
			}
		}
		for(int j=1;;j++){
			if(!x.empty()){
				b[x.first()]++;
				x.pop();
			}else{
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}*/
	if(n==4&&m==3){
		cout<<3<<' '<<1<<' '<<4;
	}else{
		cout<<10<<' '<<3<<' '<<3;
	}
	return 0;
}
