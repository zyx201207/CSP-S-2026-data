#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n]={0},ans[m+1]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		
		stack<int> b;
		int cf[m+1]={0};
		for(int j=i;j<n;j++){
			if(cf[a[j]]==1){
				cf[b.top()]=0;
				//cout<<a[j];
				while(b.top()!=a[j]){
					cf[b.top()]=0;
					b.pop();
				}
				cf[b.top()]=0; 
				b.pop();
				//cout<<b.top();
			}
				
			cf[a[j]]=1;
			b.push(a[j]);
			
		}
		while(!b.empty()){
			//cout<<b.top();
			ans[b.top()]++;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	
	return 0;
}



