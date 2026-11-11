#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],b=0,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	stack<int> q;
	cin>>n>>m;
	int ton[m+20]; 
	for(int i=1;i<=m+10;i++){
		ton[i]=0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;i++){
				if(ton[j]>0 && j==a[i]){
					b++;
					break;
				}else{
					break;
				}	
			}
			if(b==0){
				q.push(a[i]);
				cout<<" "<<a[i];
				ton[a[i]]++;
			}
			else if(b==1){
				while(!q.empty() && k){
					int x=q.top();
					if(x==k)k--;
					q.pop();
				}
			}
			b=0;
			cout<<q.size();
		}
	}
	

	return 0;
}
