#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10050];
int t[10050];
bool h[10050];
//stack <int> s;
int b[10050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int j=1;
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(h[a[i]]==0){
				h[a[i]]=1;
				b[j]=a[i];
				j++;
			}else{
				while(b[j]!=a[i]){
					b[j]=0;
					h[b[j]]=0;
					j--;
				}
				j++;
			}
		}
		for(int i=1;i<=j;i++) t[b[i]]++;
		memset(b,0,sizeof(b));
		memset(h,0,sizeof(h));
	}

	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
