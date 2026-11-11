#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[300005];
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		t=0;
		for(int j=i-1;j<n;j++){
			b[a[j]]++;
			for(int q=j-1;j>i-1;q--)
				if(a[q]==a[j]){
					for(int c=q;c<=j;c++)
						b[a[c]]--;
					break;
					}
			}
	}
	for(int i=0;i<m;i++)
		cout<<b[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	

