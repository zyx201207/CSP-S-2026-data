#include<bits/stdc++.h>
using namespace std;
int answer[500099];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n-1;i++){
		stack <int> u;
		int num[60009]={0};
		for(int j=i;j<=n-1;j++){
			if(num[a[j]]==1){
				while(u.top()!=a[j]&&!u.empty()){
					num[u.top()]--;
					u.pop();
				}
				u.pop();
				num[a[j]]=0;
			}
			num[a[j]]++;
			u.push(a[j]);
		}
		for(int j=1;j<=m;j++){
			answer[j]+=num[j];
//			cout<<j<<" "<<num[j]<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<answer[i]<<" ";
	}
	return 0;
}

