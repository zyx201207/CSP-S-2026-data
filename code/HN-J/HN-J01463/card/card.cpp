#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[200005]={0},b[100005]={0},top=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		if(a[0]==0){
			a[0]=tmp;
			top++;
		}
		else{
			for(int j=0;j<=top;j++){
				if(a[j]==tmp){
					for(int q=j;q<=top;q++) a[q]=0;
					top=j-1;
					break;
				}
			}
			a[top+1]=tmp;
			top++;
		}
		for(int i=0;i<=top;i++){
			b[a[i]]++;
		}
		//cout<<a[1]<<a[2]<<a[3]<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
